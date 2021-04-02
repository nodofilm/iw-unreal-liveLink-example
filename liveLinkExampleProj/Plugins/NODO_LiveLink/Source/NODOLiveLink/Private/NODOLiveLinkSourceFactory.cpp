// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "NODOLiveLinkSourceFactory.h"
#include "NODOLiveLinkSource.h"
#include "SNODOLiveLinkSourceFactory.h"

#define LOCTEXT_NAMESPACE "NODOLiveLinkSourceFactory"

FText UNODOLiveLinkSourceFactory::GetSourceDisplayName() const
{
	return LOCTEXT("SourceDisplayName", "NODO LiveLink");
}

FText UNODOLiveLinkSourceFactory::GetSourceTooltip() const
{
	return LOCTEXT("SourceTooltip", "Creates a connection to a NODO Wheels Data Stream");
}

TSharedPtr<SWidget> UNODOLiveLinkSourceFactory::BuildCreationPanel(FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated) const
{
	return SNew(SNODOLiveLinkSourceFactory)
		.OnOkClicked(SNODOLiveLinkSourceFactory::FOnOkClicked::CreateUObject(this, &UNODOLiveLinkSourceFactory::OnOkClicked, InOnLiveLinkSourceCreated));
}

TSharedPtr<ILiveLinkSource> UNODOLiveLinkSourceFactory::CreateSource(const FString& InConnectionString) const
{
	FIPv4Endpoint DeviceEndPoint;
	if (!FIPv4Endpoint::Parse(InConnectionString, DeviceEndPoint))
	{
		return TSharedPtr<ILiveLinkSource>();
	}

	return MakeShared<FNODOLiveLinkSource>(DeviceEndPoint);
}

void UNODOLiveLinkSourceFactory::OnOkClicked(FIPv4Endpoint InEndpoint, FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated) const
{
	InOnLiveLinkSourceCreated.ExecuteIfBound(MakeShared<FNODOLiveLinkSource>(InEndpoint), InEndpoint.ToString());
}

#undef LOCTEXT_NAMESPACE