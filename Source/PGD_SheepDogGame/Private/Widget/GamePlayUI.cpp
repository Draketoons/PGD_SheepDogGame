// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GamePlayUI.h"

void UGamePlayUI::NativeConstruct()
{

}

void UGamePlayUI::UpdateCounterText(FString value)
{
	CounterText->SetText(FText::FromString(value));
}

void UGamePlayUI::UpdateWinText(FString value)
{
	WinText->SetText(FText::FromString(value));
}
