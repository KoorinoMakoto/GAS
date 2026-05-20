// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/WitchAbilitySystemComponent.h"
#include "AbilitySystem/WitchAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//获取真实值并广播
	const UWitchAttributeSet* WitchAttributeSet = CastChecked<UWitchAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(WitchAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(WitchAttributeSet->GetMaxHealth());
	
	OnManaChanged.Broadcast(WitchAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(WitchAttributeSet->GetMaxMana());
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UWitchAttributeSet* WitchAttributeSet = CastChecked<UWitchAttributeSet>(AttributeSet);
	//生命值变动的时候会调用
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
		);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);
			}
		);
	Cast<UWitchAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				//"A.1".MatchesTag("A") will return True, "A".MatchesTag("A.1") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				//只有在Tag是Message类型的Tag时才进行广播
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
				
				// const FString Msg = FString::Printf(TEXT("Tag: %s"), *Tag.ToString());
				// GEngine->AddOnScreenDebugMessage(-1,8.f,FColor::Blue,Msg);
				
				
			}
		}	
	);
}



