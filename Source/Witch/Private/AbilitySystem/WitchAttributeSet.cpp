// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/WitchAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UWitchAttributeSet::UWitchAttributeSet()
{
	
}

void UWitchAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	//注册 health 进行复制；COND_None：无条件复制；REPNOTIFY_Always：只要在服务器上设置了值，就要进行复制，不论与原来的值相比是否有变化
	DOREPLIFETIME_CONDITION_NOTIFY(UWitchAttributeSet,Health,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWitchAttributeSet,MaxHealth,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWitchAttributeSet,Mana,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWitchAttributeSet,MaxMana,COND_None,REPNOTIFY_Always);
	
}
//属性回调函数
void UWitchAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	//告诉GAS系统，我们正在同步一个值，它的值刚从服务器拉取并改变，GAS记录这个变化，并记住旧值，以备需要回滚
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWitchAttributeSet,Health, OldHealth);
}

void UWitchAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWitchAttributeSet,MaxHealth, OldMaxHealth);
}

void UWitchAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWitchAttributeSet,Mana, OldMana);
}

void UWitchAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWitchAttributeSet,MaxMana, OldMaxMana);
}
