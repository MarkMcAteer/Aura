// Copyright McAteer Studio


#include "AbilitySystem/Data/CharacterClassInfo.h"

FCharacterClassDefaultInfo UCharacterClassInfo::GetClassDefaultInfo(ECharacterClass CharacterClass)
{
	// Return the information given the character class enum constatnt. 
	return CharacterClassInformation.FindChecked(CharacterClass);
}
