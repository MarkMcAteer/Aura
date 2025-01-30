// Copyright McAteer Studio

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "AuraAbilitySystemGlobals.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemGlobals : public UAbilitySystemGlobals
{
	GENERATED_BODY()

	/* Alloc is what is used to actually create the new gameplay effect context. */
	/* This is used so that every time we use MakeEffectContext it will be an AuraGameplayEffectContext */
	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
	
	
	
};
