// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SheepDogPlayerController.generated.h"

/**
 * 
 */
class UInputMappingContext;
UCLASS()
class ASheepDogPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ASheepDogPlayerController();
	
protected:
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Input") UInputMappingContext* MappingContext;
	
};
