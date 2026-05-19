// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/WitchAbilitySystemComponent.h"

void UWitchAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UWitchAbilitySystemComponent::EffectApplied);
}

//通过委托，可以在运行时获取某个GameplayEffect正在应用的信息
void UWitchAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                 const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1,8.f, FColor::Green,FString("EffectApplied"));
}
