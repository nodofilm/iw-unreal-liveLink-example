// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NODOLiveLinkSource.h"
#include "InertiaWheels.generated.h"



UCLASS()
class NODOLIVELINK_API AInertiaWheels : public AActor
{
	GENERATED_BODY()


	
public:	
	// Sets default values for this actor's properties
	AInertiaWheels();
	virtual bool ShouldTickIfViewportsOnly() const override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Nodo_One();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Nodo_Four();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Nodo_Three();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Nodo_Two();



};
