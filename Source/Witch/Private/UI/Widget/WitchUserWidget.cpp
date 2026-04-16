// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/WitchUserWidget.h"

void UWitchUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
