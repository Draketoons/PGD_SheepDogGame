// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/GamePlayUI.h"
#include "GameFramework/GameModeBase.h"
#include "DogGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ADogGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	UPROPERTY(EditAnywhere, Category = "Game UI")
	TSubclassOf<UGamePlayUI> GameplayUIClass;

	UPROPERTY(VisibleAnywhere, Category = "Game UI")
	UGamePlayUI* GameplayUI;
};
