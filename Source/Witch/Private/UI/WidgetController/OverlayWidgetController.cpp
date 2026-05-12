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

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UWitchAttributeSet* WitchAttributeSet = CastChecked<UWitchAttributeSet>(AttributeSet);
	//生命值变动的时候会调用
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetHealthAttribute()).AddUObject(this,&UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetMaxHealthAttribute()).AddUObject(this,&UOverlayWidgetController::MaxHealthChanged);
	
}

//生命值变化的时候，触发上面的广播委托
void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
