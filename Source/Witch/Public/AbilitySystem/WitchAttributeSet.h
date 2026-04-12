// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "WitchAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class WITCH_API UWitchAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UWitchAttributeSet();
	//注册网络同步逻辑
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	//ReplicatedUsing：告诉引擎，当服务器上的 Health 发生变化并同步到客户端时，客户端不要只悄悄更新数值，还要触发 OnRep_Health 这个函数。
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health,Category="Vital Attributes")
	//在 GAS 中，所有属性都必须是 FGameplayAttributeData 结构体，这个结构体内部其实维护了两个值：BaseValue（基础值）和 CurrentValue（当前值）。
	FGameplayAttributeData Health;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth,Category="Vital Attributes")
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana,Category="Vital Attributes")
	FGameplayAttributeData Mana;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana,Category="Vital Attributes")
	FGameplayAttributeData MaxMana;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
