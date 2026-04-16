// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WitchUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class WITCH_API UWitchUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BLueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();//每次设置WidgetController时调用
};
