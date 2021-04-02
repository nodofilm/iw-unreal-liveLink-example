// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ILiveLinkSource.h"
#include "HAL/Runnable.h"
#include "HAL/ThreadSafeBool.h"
#include "IMessageContext.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"

#include "VSerialPort.h"

class FRunnableThread;
class FSocket;
class ILiveLinkClient;
class ISocketSubsystem;

class NODOLIVELINK_API FNODOLiveLinkSource : public ILiveLinkSource, public FRunnable
{
public:

	FNODOLiveLinkSource(FIPv4Endpoint Endpoint);

	virtual ~FNODOLiveLinkSource();

	// Begin ILiveLinkSource Interface
	
	virtual void ReceiveClient(ILiveLinkClient* InClient, FGuid InSourceGuid) override;

	virtual bool IsSourceStillValid() const override;

	virtual bool RequestSourceShutdown() override;

	virtual FText GetSourceType() const override { return SourceType; };
	virtual FText GetSourceMachineName() const override { return SourceMachineName; }
	virtual FText GetSourceStatus() const override { return SourceStatus; }

	// End ILiveLinkSource Interface

	// Begin FRunnable Interface

	virtual bool Init() override { return true; }
	virtual uint32 Run() override;
	void HandleReceivedData(VSerialPort::Data data);
	void Start();
	virtual void Stop() override;
	virtual void Exit() override { }

	// End FRunnable Interface

	static bool bConnected;
	static FCriticalSection m_mutex;
	static int dataNum;
	static bool bResetZeroPosition;
	static bool bResetZeroRotation;
	static bool ShutdownRequested;


	//zeroes
	static int32_t panZero;
	static int32_t tiltZero;
	static int32_t rollZero;
	static int32_t jogaZero;
	static int32_t jogbZero;

	static float posmult;
	static float rotmult;

	//triggers
	static	bool ToStartTrigger ;
	static	bool ReverseTrigger ;
	static	bool PlayTrigger ;
	static	bool ToEndTrigger ;





private:

	ILiveLinkClient* Client;

	// Our identifier in LiveLink
	FGuid SourceGuid;

	FMessageAddress ConnectionAddress;

	FText SourceType;
	FText SourceMachineName;
	FText SourceStatus;

	FIPv4Endpoint DeviceEndpoint;

	// Socket to receive data on
	FSocket* Socket;

	// Subsystem associated to Socket
	ISocketSubsystem* SocketSubsystem;

	// Threadsafe Bool for terminating the main thread loop
	FThreadSafeBool Stopping;

	// Thread to run socket operations on
	FRunnableThread* Thread;

	// Name of the sockets thread
	FString ThreadName;

	// Time to wait between attempted receives
	FTimespan WaitTime;

	// List of subjects we've already encountered
	TSet<FName> EncounteredSubjects;

	// Buffer to receive socket data into
	TArray<uint8> RecvBuffer;
};
