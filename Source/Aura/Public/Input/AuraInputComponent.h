// Copyright McAteer Studio

#pragma once

#include "CoreMinimal.h"
#include "AuraInputConfig.h"
#include "EnhancedInputComponent.h"
#include "AuraInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	
	// Function what will bind inputs to callbacks.
	// PressedFuncType: The type of the function we'd like to bind when the input is pressedd.
	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
	void BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object,
		PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc);
	
};


template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void UAuraInputComponent::BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object,
	PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
	
	check(InputConfig);

	for (const FAuraInputAction& Action : InputConfig->AbilityInputActions)
	{
        if (Action.InputAction && Action.InputTag.IsValid())
        {
			// Pressed Function
	        if (PressedFunc)
	        {
	        	BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressedFunc, Action.InputTag);
	        }
        	// Released Function
        	if (Action.InputAction && Action.InputTag.IsValid())
        	{
        		if (ReleasedFunc)
        		{
        			BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag);
        		}
        	}
        	// Held Function
        	if (Action.InputAction && Action.InputTag.IsValid())
        	{
        		if (HeldFunc)
        		{
        			BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunc, Action.InputTag);
        		}
        	}
        }	
	}
} 
