// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"
#include "Blueprint/UserWidget.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	check(InteractWidgetClass)
	InteractWidget = CreateWidget<UUserWidget>(GetWorld(), InteractWidgetClass);
	check(InteractWidget)
	InteractWidget->AddToViewport();
	InteractWidget->SetVisibility(ESlateVisibility::Hidden);
}

void AMainHUD::ToggleInteractWidget()
{
	if (InteractWidget->GetVisibility() == ESlateVisibility::Hidden)
	{
		InteractWidget->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		InteractWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}
