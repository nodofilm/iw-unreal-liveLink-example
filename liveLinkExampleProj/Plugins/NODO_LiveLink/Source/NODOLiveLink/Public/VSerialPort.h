// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <boost/asio.hpp> 

/**
 * 
 */
class NODOLIVELINK_API VSerialPort
{

public:

	struct Data
	{
#pragma pack(push, 1)	
		char header[5];
		uint8_t ver;
		int32_t pan;
		int32_t tilt;
		int32_t roll;
		int32_t joga;
		int32_t jogb;
		uint16_t focus;
		uint16_t iris;
		uint16_t zoom;
		uint8_t toOne;
		uint8_t reverse;
		uint8_t pause;
		uint8_t forward;
		uint8_t reserved[8];
		uint8_t checksum;
		char footer[3];
#pragma pack(pop)

	};


	


public:
	VSerialPort();
	~VSerialPort();


	//port
	static FString PortNum;


	
};
