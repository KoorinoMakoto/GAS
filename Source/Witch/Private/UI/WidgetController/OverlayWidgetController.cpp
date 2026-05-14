// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/WitchAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//获取真实值并广播
	const UWitchAttributeSet* WitchAttributeSet = CastChecked<UWitchAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(WitchAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(WitchAttributeSet->GetMaxHealth());
	
	OnManaChanged.Broadcast(WitchAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(WitchAttributeSet->GetMaxMana());
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UWitchAttributeSet* WitchAttributeSet = CastChecked<UWitchAttributeSet>(AttributeSet);
	//生命值变动的时候会调用
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetHealthAttribute()).AddUObject(this,&UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetMaxHealthAttribute()).AddUObject(this,&UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetManaAttribute()).AddUObject(this,&UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetMaxManaAttribute()).AddUObject(this,&UOverlayWidgetController::MaxManaChanged);
}

//回调函数，生命值变化的时候，调用动态多播委托的广播，而对应的回调函数在蓝图中绑定
void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
//回调函数，法力值变化的时候，调用动态多播委托的广播，而对应的回调函数在蓝图中绑定
void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
