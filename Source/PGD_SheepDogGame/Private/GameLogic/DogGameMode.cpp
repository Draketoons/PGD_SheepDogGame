// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLogic/DogGameMode.h"

void ADogGameMode::AddToSheepCount(int amt)
{
	if (SheepCount >= TargetSheepCount)
		return;

	SheepCount += amt;

	UE_LOG(LogTemp, Warning, TEXT("Incrementing sheep count by: %i"), amt)

	if (SheepCount >= TargetSheepCount)
	{
		WinGame();
	}
}

void ADogGameMode::WinGame()
{
	UE_LOG(LogTemp, Error, TEXT("You Won!"))
}

