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

protected:

	virtual void Tick(float DeltaTime) override;

	
	



	
	
};
