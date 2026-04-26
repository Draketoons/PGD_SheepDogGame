// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PenTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class APenTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	APenTriggerBox();

	UFUNCTION()
	void SetPenParent(APen* pen);

private:

	UPROPERTY(EditAnywhere, Category = "Trigger Settings")
	class APen* ParentPen;

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};
