// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/WitchWidgetController.h"
#include "OverlayWidgetController.generated.h"
//动态多播委托，广播浮点数，专门针对生命值
//定义了一个名为 FOnHealthChangedSignature 的委托类型，该委托可以绑定多个函数，并在触发时传递一个 float 类型的参数（代表新生命值）。
//可以在蓝图中被绑定和广播
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);

/**
 * 
 */
//蓝图化
UCLASS(BlueprintType,Blueprintable)
class WITCH_API UOverlayWidgetController : public UWitchWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	//FOnHealthChangedSignature是委托类型，OnHealthChanged才是真正的委托对象
	//BlueprintAssignable代表我们可以在蓝图中进行绑定
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;
};
