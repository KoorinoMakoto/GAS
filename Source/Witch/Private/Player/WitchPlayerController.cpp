// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/WitchPlayerController.h"
#include "EnhancedInputSubsystems.h"

AWitchPlayerController::AWitchPlayerController()
{
	bReplicates = true;
}

void AWitchPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(WitchContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(WitchContext,0);
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
