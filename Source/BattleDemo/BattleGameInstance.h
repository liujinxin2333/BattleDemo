// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "slua.h"
#include "BattleGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEDEMO_API UBattleGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UBattleGameInstance();

    virtual void Init() override;
    virtual void Shutdown() override;

	// create global state, freed on app exit
	NS_SLUA::LuaState state;
};
