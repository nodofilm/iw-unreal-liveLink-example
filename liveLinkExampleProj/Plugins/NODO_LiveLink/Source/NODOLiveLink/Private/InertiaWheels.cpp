// Fill out your copyright notice in the Description page of Project Settings.


#include "InertiaWheels.h"

// Sets default values
AInertiaWheels::AInertiaWheels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	if (WITH_EDITOR)
	{
		PrimaryActorTick.bCanEverTick = true;
		PrimaryActorTick.bStartWithTickEnabled = true;
	}

}

// Called when the game starts or when spawned
void AInertiaWheels::BeginPlay()
{
	Super::BeginPlay();

	
//	ToStart_Nodo();
	
	
}

// Called every frame
void AInertiaWheels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FNODOLiveLinkSource::ToStartTrigger == true)
	{
		FNODOLiveLinkSource::ToStartTrigger = false;
		FEditorScriptExecutionGuard ScriptGuard;
		{
			Nodo_One();
		}
	}
	if (FNODOLiveLinkSource::ToEndTrigger == true)
	{
		FNODOLiveLinkSource::ToEndTrigger = false;
		FEditorScriptExecutionGuard ScriptGuard;
		{
			Nodo_Four();
		}
	}
	if (FNODOLiveLinkSource::ReverseTrigger == true)
	{
		FNODOLiveLinkSource::ReverseTrigger = false;
		FEditorScriptExecutionGuard ScriptGuard;
		{
			Nodo_Two();
		}
	}
	if (FNODOLiveLinkSource::PlayTrigger == true)
	{
		FNODOLiveLinkSource::PlayTrigger = false;
		FEditorScriptExecutionGuard ScriptGuard;
		{
			Nodo_Three();
		}
	}

}







bool AInertiaWheels::ShouldTickIfViewportsOnly() const
{
	return true;
}