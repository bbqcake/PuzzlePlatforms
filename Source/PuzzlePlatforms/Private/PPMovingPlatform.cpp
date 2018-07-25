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

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

void APPMovingPlatform::Tick(float DeltaTime)
{
	//static mesh doesnt have a tick so super
	//isnt needed but good to be safe
	Super::Tick(DeltaTime);	

	if (ActiveTriggers > 0)
	{
		if (HasAuthority())
		{
			FVector Location = GetActorLocation();
			// Gives us the length of the vector
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLength)
			{
				//This swaps Target and Location Around wiith a temp variable (swap)
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += Speed * DeltaTime * Direction;
			SetActorLocation(Location);
		};

	}
	
	
}

void APPMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void APPMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}


