// Fill out your copyright notice in the Description page of Project Settings.

#include "PPGameInstance.h"

#include "Engine/Engine.h"


UPPGameInstance::UPPGameInstance(const FObjectInitializer & ObjectInitializser)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UPPGameInstance::init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPPGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");


}

void UPPGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	// need the PrintF here to print the address
	Engine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);


}

