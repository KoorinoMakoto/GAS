// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WitchHUD.generated.h"

class UWitchUserWidget;
/**
 * 
 */
UCLASS()
class WITCH_API AWitchHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TObjectPtr<UWitchUserWidget> OverlayWidget;
	
protected:
	virtual void BeginPlay() override;
	
private:
	
	//要创建Widget，需要知道具体的Widget类
	UPROPERTY(EditAnywhere)
	TSubclassOf<UWitchUserWidget> OverlayWidgetClass;
};
