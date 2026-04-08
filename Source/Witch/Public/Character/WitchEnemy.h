// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/WitchCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "WitchEnemy.generated.h"

/**
 * 
 */
UCLASS()
class WITCH_API AWitchEnemy : public AWitchCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
};
