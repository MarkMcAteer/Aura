// Copyright McAteer Studio

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "CombatInterface.generated.h"

class UNiagaraSystem;
class UAnimMontage;

USTRUCT(BlueprintType)
struct FTaggedMontage
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimMontage* Montage = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FGameplayTag MontageTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FGameplayTag SocketTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USoundBase* ImpactSound = nullptr;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API ICombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual int32 GetPlayerLevel();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FVector GetCombatSocketLocation(const FGameplayTag& MontageTag);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateFacingTarget(const FVector& Target);

	// Automatically generate a virtual native version that we can override in c++
	// This is because if we did only BlueprintCallable we could not override in different enemies. 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UAnimMontage* GetHitReactMontage();

	virtual void Die() = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsDead() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	AActor* GetAvatar();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TArray<FTaggedMontage> GetAttackMontages();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UNiagaraSystem* GetBloodEffect();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FTaggedMontage GetTaggedMontageByTag(const FGameplayTag& MontageTag);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 GetMinionCount();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void IncrementMinionCount(int32 Amount);
};
