// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/WitchEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/WitchAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AWitchEffectActor::AWitchEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere  = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AWitchEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherOverlappedComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	//TODO: Change this to apply a Gameplay Effect.
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{;	//GetAttributeSet返回一个UAttributeSet对象,我们再将其转化为UWitchAttributeSet
		const UWitchAttributeSet* WitchAttributeSet = Cast<UWitchAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UWitchAttributeSet::StaticClass()));
		UWitchAttributeSet* MutableWitchAttributes = const_cast<UWitchAttributeSet*>(WitchAttributeSet); 
		MutableWitchAttributes->SetHealth(WitchAttributeSet->GetHealth()+25.f);
		Destroy();
	}
}

void AWitchEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

// Called when the game starts or when spawned
void AWitchEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this,&AWitchEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this,&AWitchEffectActor::EndOverlap);
}



