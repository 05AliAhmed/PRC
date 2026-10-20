// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PRCSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class PRC_API UPRCSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "SAVE")
	int32 Score = 0;

	UPROPERTY(BlueprintReadWrite, Category = "SAVE")
	float Hp = 100.f;

	UPROPERTY(BlueprintReadWrite, Category = "SAVE")
	TArray<FString> Inventory;
};
