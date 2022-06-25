// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoGameFeaturesAnimInstance.h"
#include "AbilitySystemComponent.h"

void UDemoGameFeaturesAnimInstance::NativeInitializeAnimation()
{
	if (AActor* MyActor = GetOwningActor())
	{
		UAbilitySystemComponent* AbilityComponent = MyActor->FindComponentByClass<UAbilitySystemComponent>();
		if (AbilityComponent)
		{
			InitializeWithAbilitySystem(AbilityComponent);
		}
	}

	Super::NativeInitializeAnimation();
}

void UDemoGameFeaturesAnimInstance::InitializeWithAbilitySystem(UAbilitySystemComponent* AbilityComponent)
{
	GameplayTagPropertyMap.Initialize(this, AbilityComponent);
	ReceiveAbilitySystem(AbilityComponent);
}