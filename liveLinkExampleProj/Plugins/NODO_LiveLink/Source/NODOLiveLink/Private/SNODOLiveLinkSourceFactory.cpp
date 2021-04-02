// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SNODOLiveLinkSourceFactory.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "VSerialPort.h"

#define LOCTEXT_NAMESPACE "NODOLiveLinkSourceEditor"

void SNODOLiveLinkSourceFactory::Construct(const FArguments& Args)
{
	OkClicked = Args._OnOkClicked;

	FIPv4Endpoint Endpoint;
	Endpoint.Address = FIPv4Address::Any;
	Endpoint.Port = 54321;

	FString portnum = "COM14";

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(250)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Left)
				.FillWidth(0.5f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("SerialPortNumber", "Port Number"))
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.FillWidth(0.5f)
				[
					SAssignNew(EditabledText, SEditableTextBox)
					.Text(FText::FromString(portnum))
					.OnTextCommitted(this, &SNODOLiveLinkSourceFactory::OnEndpointChanged)
				]
			]
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Right)
			.AutoHeight()
			[
				SNew(SButton)
				.OnClicked(this, &SNODOLiveLinkSourceFactory::OnOkClicked)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Ok", "Ok"))
				]
			]
		]
	];
}

void SNODOLiveLinkSourceFactory::OnEndpointChanged(const FText& NewValue, ETextCommit::Type)
{
	TSharedPtr<SEditableTextBox> EditabledTextPin = EditabledText.Pin();
	if (EditabledTextPin.IsValid())
	{
		EditabledTextPin->SetText(NewValue);
		/*
		FIPv4Endpoint Endpoint;
		if (!FIPv4Endpoint::Parse(NewValue.ToString(), Endpoint))
		{
			Endpoint.Address = FIPv4Address::Any;
			Endpoint.Port = 54321;
			EditabledTextPin->SetText(FText::FromString(Endpoint.ToString()));
		}
		*/
	}
}

FReply SNODOLiveLinkSourceFactory::OnOkClicked()
{
	TSharedPtr<SEditableTextBox> EditabledTextPin = EditabledText.Pin();
	if (EditabledTextPin.IsValid())
	{
		VSerialPort::PortNum = EditabledTextPin->GetText().ToString();
		
		FIPv4Endpoint Endpoint;
		
		OkClicked.ExecuteIfBound(Endpoint);
		
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE