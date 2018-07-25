// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PPMovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API APPMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:

	APPMovingPlatform();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float Speed = 20;
	// this MakeEditWidget makes a little dimaond we can set our location to!
	UPROPERTY(EditAnywhere, Category = "Moving Platform", Meta = (MakeEditWidget = true)) 
	FVector TargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();


protected:

	virtual void Tick(float DeltaTime) override;

private:
	FVector GlobalTargetLocation;

	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;

	
	



	
	
};
