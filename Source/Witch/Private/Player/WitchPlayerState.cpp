// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/WitchPlayerState.h"

#include "AbilitySystem/WitchAbilitySystemComponent.h"
#include "AbilitySystem/WitchAttributeSet.h"

AWitchPlayerState::AWitchPlayerState()
{
	NetUpdateFrequency = 100.f;//服务器更新数据到客户端的频率
	
	AbilitySystemComponent = CreateDefaultSubobject<UWitchAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet  = CreateDefaultSubobject<UWitchAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AWitchPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
