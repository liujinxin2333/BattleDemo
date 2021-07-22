// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BattleDemo : ModuleRules
{
	public BattleDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		// 配置预编译头文件的使用方式
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs; 

        // 增加slua_unreal到依赖库和搜索路径中
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		PrivateDependencyModuleNames.AddRange(new string[] { "slua_unreal", "Slate", "SlateCore", "UMG" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "slua_unreal" });
        PublicIncludePathModuleNames.AddRange(new string[] { "slua_unreal" });
	}
}
