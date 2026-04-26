// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLogic/PenTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Character/AICharacter.h"
#include "Core/Pen.h"

APenTriggerBox::APenTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &APenTriggerBox::OnOverlapBegin);
}

void APenTriggerBox::SetPenParent(APen* pen)
{
	if (!pen)
		return;

	UE_LOG(LogTemp, Warning, TEXT("Parent Pen Set!"))
	ParentPen = pen;
}

void APenTriggerBox::BeginPlay()
{
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Red, true, -1, 0, 5);
}


void APenTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Error, TEXT("Overlapped"))

	AAICharacter* currentAICharacter = Cast<AAICharacter>(OtherActor);

	if (!ParentPen)
		return;

	if (!currentAICharacter)
		return;

	ParentPen->IncrementSheepCount(1);
	currentAICharacter->InPen = true;
}