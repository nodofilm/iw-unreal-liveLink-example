// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PublicFunctions.generated.h"

/**
 * 
 */


UCLASS()
class NODOLIVELINK_API UPublicFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		

	UFUNCTION(BlueprintCallable, Category = "NODO")
		static void ResetZeroPosition();

	UFUNCTION(BlueprintCallable, Category = "NODO")
		static void ResetZeroRotation();

	UFUNCTION(BlueprintCallable, Category = "NODO")
		static void SetRotationMultiplier(float mult);
	UFUNCTION(BlueprintCallable, Category = "NODO")
		static void SetPositionMultiplier(float mult);



};
