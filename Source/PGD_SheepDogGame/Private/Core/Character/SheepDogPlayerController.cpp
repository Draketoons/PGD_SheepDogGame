// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Character/SheepDogPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

ASheepDogPlayerController::ASheepDogPlayerController()
{
}

void ASheepDogPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (!MappingContext)
	{
		return;
	}

	if (UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		LocalPlayerSubsystem->AddMappingContext(MappingContext, 0);
		UE_LOG(LogTemp, Warning, TEXT("Input mapping context added."));
	}
}
