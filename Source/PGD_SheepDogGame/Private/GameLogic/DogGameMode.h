// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DogGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ADogGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void AddToSheepCount(int amt);

	UFUNCTION()
	void WinGame();

private:
	UPROPERTY(EditAnywhere, Category = "Game Stats")
	int SheepCount = 0;

	UPROPERTY(EditAnywhere, Category = "Game Settings")
	int TargetSheepCount;
};
