// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/AC_Sheep.h"
#include "Character/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Core/Character/DogCharacter.h"
#include "DrawDebugHelpers.h"
#include "Character/AICharacter.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AIController = Cast<AAC_Sheep>(GetController());

	TArray<AActor*> players;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADogCharacter::StaticClass(), players);

	PlayerObject = Cast<ACharacter>(players[0]);

	if (PlayerObject)
		UE_LOG(LogTemp, Warning, TEXT("Player found!"));
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), DetectionRadius, 10, FColor::Red, false, -1.0f, 1.0, 1.0);

	if (!PlayerObject)
		return;

	if (InPen)
		return;

	float playerDistance = FVector::Dist(GetActorLocation(), PlayerObject->GetActorLocation());

	if (playerDistance < DetectionRadius)
	{
		AvoidPlayer();
	}

}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAICharacter::AvoidPlayer()
{
	if (PlayerObject)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AIController Location: %f, %f, %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z)
		FVector playerDirection = PlayerObject->GetActorLocation() - GetActorLocation();

		FVector targetLocation = -playerDirection * AvoidOffset;

		DrawDebugSphere(GetWorld(), targetLocation * AvoidOffset, 50, 10, FColor::Green, false, -1.0f, 1.0, 1.0);

		AIController->MoveToLocation(targetLocation * AvoidOffset);
	}
}

