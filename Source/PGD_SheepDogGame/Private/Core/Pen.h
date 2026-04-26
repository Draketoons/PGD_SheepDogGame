// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameLogic/DogGameMode.h"
#include "GameLogic/PenTriggerBox.h"
#include "GameFramework/Actor.h"
#include "Pen.generated.h"

UCLASS()
class APen : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APen();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void IncrementSheepCount(int amount);

private:

	UPROPERTY(EditAnywhere, Category = "Pen Settings")
	ADogGameMode* GameMode;

	UPROPERTY(EditAnywhere, Category = "Pen Settings")
	APenTriggerBox* TriggerBox;
};
