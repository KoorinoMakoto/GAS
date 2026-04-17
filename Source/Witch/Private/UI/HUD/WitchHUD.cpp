// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/WitchHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/WitchUserWidget.h"

void AWitchHUD::BeginPlay()
{
	Super::BeginPlay();
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(),OverlayWidgetClass);
	Widget->AddToViewport();
}
