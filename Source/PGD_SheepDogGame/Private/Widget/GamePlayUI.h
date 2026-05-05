// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GamePlayUI.generated.h"

/**
 * 
 */
UCLASS()
class UGamePlayUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* CounterText = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* WinText = nullptr;

public:
	void UpdateCounterText(FString value);
	void UpdateWinText(FString value);
};
