// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/WitchAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//获取真实值并广播
	const UWitchAttributeSet* WitchAttributeSet = CastChecked<UWitchAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(WitchAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(WitchAttributeSet->GetMaxHealth());
	
}
