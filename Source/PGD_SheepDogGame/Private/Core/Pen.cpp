// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Pen.h"
#include "GameLogic/DogGameMode.h"

// Sets default values
APen::APen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APen::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->SetPenParent(this);

	GameMode = Cast<ADogGameMode>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void APen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APen::IncrementSheepCount(int amount)
{
	GameMode->AddToSheepCount(amount);
}

