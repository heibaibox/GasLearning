// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_Jump.generated.h"

class ACorePlayerCharacter;
/**
 * 
 */
UCLASS(Abstract)
class GASLEARNING_API UGA_Jump : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UGA_Jump(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void CharacterJumpStart();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void CharacterJumpStop();

	UFUNCTION(BlueprintCallable)
	ACorePlayerCharacter* GetOwningCharacter() const;
};
