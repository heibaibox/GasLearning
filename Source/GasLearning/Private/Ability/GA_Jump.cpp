// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/GA_Jump.h"

#include "Player/CorePlayerCharacter.h"

UGA_Jump::UGA_Jump(const FObjectInitializer& ObjectInitializer)
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
}

bool UGA_Jump::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
	FGameplayTagContainer* OptionalRelevantTags) const
{
	const ACorePlayerCharacter* OwnCharacter = GetOwningCharacter();
	if(!OwnCharacter||!OwnCharacter->CanJump())
	{
		return false;
	}
	
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UGA_Jump::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	CharacterJumpStop();
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UGA_Jump::CharacterJumpStart()
{
	if (ACorePlayerCharacter* LyraCharacter = GetOwningCharacter())
	{
		if (LyraCharacter->IsLocallyControlled() && !LyraCharacter->bPressedJump)
		{
			LyraCharacter->UnCrouch();
			LyraCharacter->Jump();
		}
	}
}

void UGA_Jump::CharacterJumpStop()
{
	if (ACorePlayerCharacter* LyraCharacter = GetOwningCharacter())
	{
		if (LyraCharacter->IsLocallyControlled() && LyraCharacter->bPressedJump)
		{
			LyraCharacter->StopJumping();
		}
	}
}

ACorePlayerCharacter* UGA_Jump::GetOwningCharacter() const
{
	return (CurrentActorInfo?Cast<ACorePlayerCharacter>(CurrentActorInfo->AvatarActor.Get()):nullptr);
}
