// Fill out your copyright notice in the Description page of Project Settings.
#include "BattleGameInstance.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFileManager.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/FileManager.h"

UBattleGameInstance::UBattleGameInstance() : state("main",this){

}

void UBattleGameInstance::Init()
{
    Super::Init();

	state.init();

	state.setLoadFileDelegate([](const char* fn, FString& filepath)->TArray<uint8> {

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		FString path = FPaths::ProjectContentDir();
		FString filename = UTF8_TO_TCHAR(fn);
		path /= "Lua";
		path /= filename.Replace(TEXT("."), TEXT("/"));

		TArray<uint8> Content;
		TArray<FString> luaExts = { UTF8_TO_TCHAR(".lua"), UTF8_TO_TCHAR(".luac") };
		for (auto& it : luaExts) {
			auto fullPath = path + *it;

			FFileHelper::LoadFileToArray(Content, *fullPath);
			if (Content.Num() > 0) {
				filepath = fullPath;
				return MoveTemp(Content);
			}
		}

		return MoveTemp(Content);
	});

    UE_LOG(LogTemp, Warning, TEXT("Initiating Slua"));

    state.doFile("init");
}

void UBattleGameInstance::Shutdown()
{
    Super::Shutdown();

    state.close();

    UE_LOG(LogTemp, Warning, TEXT("Closing Slua"));
}
