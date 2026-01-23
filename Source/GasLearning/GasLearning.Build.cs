// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GasLearning : ModuleRules
{
	public GasLearning(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});

		PublicIncludePaths.AddRange(new string[] {
			"GasLearning",
			"GasLearning/Variant_Horror",
			"GasLearning/Variant_Horror/UI",
			"GasLearning/Variant_Shooter",
			"GasLearning/Variant_Shooter/AI",
			"GasLearning/Variant_Shooter/UI",
			"GasLearning/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
