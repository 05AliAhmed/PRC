// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RealHealthComponent.generated.h"
// Fires every hit — carries new HP value as float
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnHealthChanged, float, NewHealth);

// Fires once at 0 HP — no data payload needed
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDeath);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRC_API URealHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URealHealthComponent();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float MaxHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float CurrentHealth = 0.f;
	UPROPERTY(BlueprintAssignable) FOnHealthChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable) FOnPlayerDeath OnPlayerDeath;
	// delegate UPROPERTY slots go here after the DECLARE macros above
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Amount);
	UFUNCTION(BlueprintCallable)
	void Heal(float Amount);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
