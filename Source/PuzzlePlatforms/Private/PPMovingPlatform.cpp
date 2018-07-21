// Fill out your copyright notice in the Description page of Project Settings.

#include "PPMovingPlatform.h"


APPMovingPlatform::APPMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	// this adds transforms to our static mesh
	SetMobility(EComponentMobility::Movable);
}

void APPMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void APPMovingPlatform::Tick(float DeltaTime)
{
	//static mesh doesnt have a tick so super
	//isnt needed but good to be safe
	Super::Tick(DeltaTime);	
	
	if (HasAuthority())
	{ 
	FVector Location = GetActorLocation();
	Location += FVector(Speed * DeltaTime, 0, 0);
	SetActorLocation(Location);
	};
}



