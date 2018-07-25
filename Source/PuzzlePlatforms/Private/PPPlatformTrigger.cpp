// Fill out your copyright notice in the Description page of Project Settings.

#include "PPPlatformTrigger.h"
#include "Components/BoxComponent.h"

#include "PPMovingPlatform.h"


// Sets default values
APPPlatformTrigger::APPPlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;

	RootComponent = TriggerVolume;
	// & points us to the right address
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APPPlatformTrigger::OnOverlapBegin);

	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APPPlatformTrigger::OnOverlapEnd);

}

// Called when the game starts or when spawned
void APPPlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APPPlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APPPlatformTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (APPMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->AddActiveTrigger();
	}
}

void APPPlatformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	for (APPMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->RemoveActiveTrigger();
	}
}

