// Copyright McAteer Studio

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	// Enemy interface 
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	/*
	 * Combat Interface 
	 */

	virtual int32 GetPlayerLevel() override;
	
	/*
	 * End Combat Interface 
	 */

protected:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults");
	int32 Level = 1;
	
};
