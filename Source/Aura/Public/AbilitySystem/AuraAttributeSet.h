// Copyright McAteer Studio

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
	
};

// typedef is specific to the FGameplayAttribute() signature, but TStaticFuncPtr is generic to any signature
//typedef TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFuncPtr;
template <class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;


	/*
	 * Primary Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

	/*
	* Secondary Attributes
	*/

	// Armor Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	// ArmorPenetration Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration);

	// BlockChance Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);

	// CriticalHitChance Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance);

	// CriticalHitDamage Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage);

	// CriticalHitResistance Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance);

	// HealthRegeneration Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration);

	// ManaRegeneration Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration);

	
	// MaxMana Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	// MaxHealth Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Secondary Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	/*
	 * Resistance Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FireResistance, Category = "Resistance Attributes")
	FGameplayAttributeData FireResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, FireResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_LightningResistance, Category = "Resistance Attributes")
	FGameplayAttributeData LightningResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, LightningResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArcaneResistance, Category = "Arcane Attributes")
	FGameplayAttributeData ArcaneResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArcaneResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PhysicalResistance, Category = "Resistance Attributes")
	FGameplayAttributeData PhysicalResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, PhysicalResistance);
	
	/*
	 * Vital Attributes
	 */
	
	// Health Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health)
	
	// Mana Property
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	/*
	 * Meta Attributes
	 */

	UPROPERTY(BlueprintReadOnly, Category = "Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, IncomingDamage);
	
	/*
	 *  Attribute OnRep Functions
	 */
	
	// Health Function
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	// MaxHealth Function
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	// Mana Function
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	// MaxMana Function
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	// Strength Function
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	
	// Intelligence Function
    UFUNCTION()
    void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	// Resilience Function
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	// Vigor Function
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	// Armor Function
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	
	// ArmorPenetration Function
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	// BlockChance Function
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;
	
	// CriticalHitChance Function
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	// CriticalHitDamage Function
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	// CriticalHitResistance Function
	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;
	
	// HealthRegeneration Function
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

	// ManaRegeneration Function
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;

	// FireResistance Function
	UFUNCTION()
	void OnRep_FireResistance(const FGameplayAttributeData& OldFireResistance) const;
	
	// LightningResistance Function
	UFUNCTION()
	void OnRep_LightningResistance(const FGameplayAttributeData& OldLightningResistance) const;

	// ArcaneResistance Function
	UFUNCTION()
	void OnRep_ArcaneResistance(const FGameplayAttributeData& OldArcaneResistance) const;

	// PhysicalResistance Function
	UFUNCTION()
	void OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance) const;


private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;

	void ShowFloatingText(const FEffectProperties& Props, float Damage, bool bBlockedHit, bool bCriticalHit) const;
	
};
