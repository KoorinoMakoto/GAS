// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WitchEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class WITCH_API AWitchEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWitchEffectActor();
	

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//进入蓝图，在创建具体的游戏效果后，调用
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	//实现即时游戏效果,能在蓝图中设置
	//EditAnywhere + BlueprintReadOnly 是 UE 开发中最标准、最常用的黄金组合之一。
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass; 

};
