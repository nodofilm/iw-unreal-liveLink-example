// Fill out your copyright notice in the Description page of Project Settings.


#include "PublicFunctions.h"
#include "NODOLiveLinkSource.h"

void UPublicFunctions::ResetZeroPosition()
{
  FNODOLiveLinkSource::bResetZeroPosition = true;
}

void UPublicFunctions::ResetZeroRotation()
{
	FNODOLiveLinkSource::bResetZeroRotation = true;
}
void UPublicFunctions::SetRotationMultiplier(float mult)
{
	FNODOLiveLinkSource::rotmult = mult;
}
void UPublicFunctions::SetPositionMultiplier(float mult)
{
	FNODOLiveLinkSource::posmult = mult;
}

