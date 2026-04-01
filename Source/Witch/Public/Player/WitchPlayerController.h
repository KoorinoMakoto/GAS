// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WitchPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class WITCH_API AWitchPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AWitchPlayerController();
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> WitchContext;
};
