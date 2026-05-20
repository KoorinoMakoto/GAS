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
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetHealthAttribute()).AddUObject(this,&UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetMaxHealthAttribute()).AddUObject(this,&UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetManaAttribute()).AddUObject(this,&UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WitchAttributeSet->GetMaxManaAttribute()).AddUObject(this,&UOverlayWidgetController::MaxManaChanged);
	
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

//回调函数，生命值变化的时候，调用动态多播委托的广播，而对应的回调函数在蓝图中绑定,即WBP_HealthGlobe和WBP_ManaGlobe中,需要先获取WidgetController才能绑定其中的委托
void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
//回调函数，法力值变化的时候，调用动态多播委托的广播，而对应的回调函数在蓝图中绑定，即WBP_HealthGlobe和WBP_ManaGlobe中
void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
