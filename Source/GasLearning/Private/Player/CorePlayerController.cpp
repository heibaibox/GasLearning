// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CorePlayerController.h"

#include "AbilitySystemComponent.h"
#include "Player/CorePlayerCharacter.h"

void ACorePlayerController::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);

	if (ACorePlayerCharacter* PlayerCharacter = Cast<ACorePlayerCharacter>(P))
	{
		PlayerCharacter->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerCharacter, PlayerCharacter);
	}
}
