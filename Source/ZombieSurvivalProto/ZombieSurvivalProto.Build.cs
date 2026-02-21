// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ZombieSurvivalProto : ModuleRules
{
	public ZombieSurvivalProto(ReadOnlyTargetRules Target) : base(Target)
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

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ZombieSurvivalProto",
			"ZombieSurvivalProto/Variant_Platforming",
			"ZombieSurvivalProto/Variant_Platforming/Animation",
			"ZombieSurvivalProto/Variant_Combat",
			"ZombieSurvivalProto/Variant_Combat/AI",
			"ZombieSurvivalProto/Variant_Combat/Animation",
			"ZombieSurvivalProto/Variant_Combat/Gameplay",
			"ZombieSurvivalProto/Variant_Combat/Interfaces",
			"ZombieSurvivalProto/Variant_Combat/UI",
			"ZombieSurvivalProto/Variant_SideScrolling",
			"ZombieSurvivalProto/Variant_SideScrolling/AI",
			"ZombieSurvivalProto/Variant_SideScrolling/Gameplay",
			"ZombieSurvivalProto/Variant_SideScrolling/Interfaces",
			"ZombieSurvivalProto/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
