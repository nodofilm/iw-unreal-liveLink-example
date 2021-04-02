// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NODOLiveLinkSource.h"

#include "ILiveLinkClient.h"
#include "LiveLinkTypes.h"
#include "Roles/LiveLinkAnimationRole.h"
#include "Roles/LiveLinkAnimationTypes.h"
#include "Roles/LiveLinkCameraRole.h"
#include "Roles/LiveLinkCameraTypes.h"
#include "Roles/LiveLinkBasicRole.h"
#include "Roles/LiveLinkBasicTypes.h"

#include "Async/Async.h"
#include "Common/UdpSocketBuilder.h"
#include "HAL/RunnableThread.h"
#include "Json.h"
#include "Sockets.h"
#include "SocketSubsystem.h"



#define LOCTEXT_NAMESPACE "NODOLiveLinkSource"

#define RECV_BUFFER_SIZE 1024 * 1024

bool FNODOLiveLinkSource::bConnected = false;
bool bCreateSubject = true;
FCriticalSection FNODOLiveLinkSource::m_mutex;
int FNODOLiveLinkSource::dataNum = 13;

int32_t FNODOLiveLinkSource::panZero;
int32_t FNODOLiveLinkSource::tiltZero;
int32_t FNODOLiveLinkSource::rollZero;
int32_t FNODOLiveLinkSource::jogaZero;
int32_t FNODOLiveLinkSource::jogbZero;
bool FNODOLiveLinkSource::bResetZeroPosition = false;
bool FNODOLiveLinkSource::bResetZeroRotation = false;
bool FNODOLiveLinkSource::ShutdownRequested = false;

bool FNODOLiveLinkSource::ToStartTrigger = false;
bool FNODOLiveLinkSource::ReverseTrigger = false;
bool FNODOLiveLinkSource::PlayTrigger = false;
bool FNODOLiveLinkSource::ToEndTrigger = false;

float FNODOLiveLinkSource::posmult =0.01;
float FNODOLiveLinkSource::rotmult = 0.001;



FNODOLiveLinkSource::FNODOLiveLinkSource(FIPv4Endpoint InEndpoint)
: Socket(nullptr)
, Stopping(false)
, Thread(nullptr)
, WaitTime(FTimespan::FromMilliseconds(100))
{
	// defaults
	DeviceEndpoint = InEndpoint;

	SourceStatus = LOCTEXT("SourceStatus_DeviceNotFound", "Device Not Found");
	SourceType = LOCTEXT("NODOLiveLinkSourceType", "NODO LiveLink");
	SourceMachineName = LOCTEXT("NODOLiveLinkSourceMachineName", "localhost");
	

	
		Start();
		SourceStatus = LOCTEXT("SourceStatus_Receiving", "Receiving");

	
}

FNODOLiveLinkSource::~FNODOLiveLinkSource()
{
	Stop();
	if (Thread != nullptr)
	{
		Stopping = true;
		Thread->WaitForCompletion();
		delete Thread;
		Thread = nullptr;
	}
	
	
	bCreateSubject = true;
}

void FNODOLiveLinkSource::ReceiveClient(ILiveLinkClient* InClient, FGuid InSourceGuid)
{
	Client = InClient;
	SourceGuid = InSourceGuid;
}


bool FNODOLiveLinkSource::IsSourceStillValid() const
{
	// Source is valid if we have a valid thread and socket
	bool bIsSourceValid = !Stopping && Thread != nullptr && Socket != nullptr;
	return bIsSourceValid;
}


bool FNODOLiveLinkSource::RequestSourceShutdown()
{
	Stop();
	bCreateSubject = true;
	return true;
}
// FRunnable interface

void FNODOLiveLinkSource::Start()
{
	ThreadName = "NODO Data Receiver ";
	ThreadName.AppendInt(FAsyncThreadIndex::GetNext());
	
	Thread = FRunnableThread::Create(this, *ThreadName, 128 * 1024, TPri_AboveNormal, FPlatformAffinity::GetPoolThreadMask());
}

void FNODOLiveLinkSource::Stop()
{
	Stopping = true;
	ShutdownRequested = true;
	bConnected = false;
}

template<class T>T reverseBytes(T valueIn)
{
	T valueOut;
	uint8_t * pSrc = (uint8_t *)&valueIn + sizeof(valueIn) - 1;
	uint8_t * pDst = (uint8_t *)&valueOut;
	int k = sizeof(valueIn);

	while (k-- > 0)
	{
		*pDst++ = *pSrc--;
	}

	return valueOut;
}


char toOnePrev;
char reversePrev;
char pausePrev;
char forwardPrev;

uint32 FNODOLiveLinkSource::Run()
{

	static boost::asio::io_service io;
	static boost::asio::serial_port port(io);

	std::string p = std::string(TCHAR_TO_UTF8(*VSerialPort::PortNum));
	port.open(p);
	port.set_option(boost::asio::serial_port_base::baud_rate(921600));

	if (!port.is_open())
	{
		Stopping = true;
		bConnected = false;
		return false;
	}
	bConnected = true;

	while (ShutdownRequested == false)
	{
		char header[] = "IWVPx";

		uint8_t cnt = 0;
		char hdr[] = "IWVPx";
		uint8_t obuf[256]; // arbitrary size, larger than largest expected buffer
		for (size_t i = 0; i < 256; ++i) obuf[i] = 0;

		uint8_t hidx = 0;
		while (strncmp(hdr, header, sizeof(header)))
		{
			boost::asio::read(port, boost::asio::buffer(&hdr, 5));
		}

		boost::asio::read(port, boost::asio::buffer(obuf, sizeof(VSerialPort::Data)));


		VSerialPort::Data d = {};
		memcpy(&d, obuf, sizeof(d));

		d.pan = reverseBytes(d.pan);
		d.tilt = reverseBytes(d.tilt);
		d.roll = reverseBytes(d.roll);
		d.joga = reverseBytes(d.joga);
		d.jogb = reverseBytes(d.jogb);

		d.focus = reverseBytes(d.focus);
		d.iris = reverseBytes(d.iris);
		d.zoom = reverseBytes(d.zoom);


		char toOne = d.toOne;
		char reverse = d.reverse;
		char pause = d.pause;
		char forward = d.forward;

		if (bCreateSubject == true)
		{
			panZero = d.pan;
			tiltZero = d.tilt;
			rollZero = d.roll;
			jogaZero = d.joga;
			jogbZero = d.jogb;
		}

		if (bResetZeroPosition == true)
		{
			bResetZeroPosition = false;
			jogaZero = d.joga;
			jogbZero = d.jogb;
		}
		if (bResetZeroRotation == true)
		{
			bResetZeroRotation = false;
			panZero = d.pan;
			tiltZero = d.tilt;
			rollZero = d.roll;
		}
		

		d.pan = (d.pan - panZero);
		d.tilt = (d.tilt - tiltZero);
		d.roll = (d.roll - rollZero);
		d.joga = (d.joga - jogaZero);
		d.jogb = (d.jogb -jogbZero);

		


		HandleReceivedData(d);
	}

	port.close();
	return 0;
}

void FNODOLiveLinkSource::HandleReceivedData(VSerialPort::Data data)
{
	if (bConnected == true)	{


		float pan = float(data.pan);
		float tilt = float(data.tilt);
		float joga = float(data.joga);
		float jogb = float(data.jogb); 
		float roll = float(data.roll);
		float iris = float(data.iris);
		float focus = float(data.focus);
		float zoom = float(data.zoom);



		//


		pan = pan * rotmult;
		tilt = tilt * rotmult;
		roll = roll * rotmult;
		joga = joga * posmult;
		jogb = jogb * posmult;

	//	UE_LOG(LogTemp, Warning, TEXT("data %f, %f, %f"), pan, tilt, joga);

		if (data.toOne != toOnePrev && bCreateSubject == false)
		{
			toOnePrev = data.toOne;
			ToStartTrigger = true;
		}
		if (data.reverse != reversePrev && bCreateSubject == false)
		{
			reversePrev = data.reverse;
			ReverseTrigger = true;
		}
		if (data.pause != pausePrev && bCreateSubject == false)
		{
			pausePrev = data.pause;
			PlayTrigger = true;
		}
		if (data.forward != forwardPrev && bCreateSubject == false)
		{
			forwardPrev = data.forward;
			ToEndTrigger = true;
		}

		
		FName SubjectName("NODO");
		if (bCreateSubject)
		{

			FLiveLinkStaticDataStruct StaticDataStruct = FLiveLinkStaticDataStruct(FLiveLinkCameraStaticData::StaticStruct());
			FLiveLinkCameraStaticData& StaticData = *StaticDataStruct.Cast<FLiveLinkCameraStaticData>();

		
			Client->PushSubjectStaticData_AnyThread({ SourceGuid, SubjectName }, ULiveLinkCameraRole::StaticClass(), MoveTemp(StaticDataStruct));
			EncounteredSubjects.Add(SubjectName);

			bCreateSubject = false;
		}

		FLiveLinkFrameDataStruct FrameDataStruct = FLiveLinkFrameDataStruct(FLiveLinkCameraFrameData::StaticStruct());
		FLiveLinkCameraFrameData& FrameData = *FrameDataStruct.Cast<FLiveLinkCameraFrameData>();

		

		FVector BoneLocation(0,jogb, joga);

		FRotator camRot(tilt, pan, roll);

		FQuat BoneQuat(camRot);

		FVector BoneScale(1, 1, 1);		


		FrameData.Transform = FTransform(BoneQuat, BoneLocation, BoneScale);

		//fiz
		FrameData.Aperture = iris / 255.0;
		FrameData.FocalLength = zoom / 255.0;
		FrameData.FocusDistance = focus / 255.0;

		Client->PushSubjectFrameData_AnyThread({ SourceGuid, SubjectName }, MoveTemp(FrameDataStruct));

	}

	
}



#undef LOCTEXT_NAMESPACE
