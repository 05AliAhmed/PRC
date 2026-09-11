// Fill out your copyright notice in the Description page of Project Settings.


#include "RealHealthComponent.h"

// Sets default values for this component's properties
URealHealthComponent::URealHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URealHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void URealHealthComponent::TakeDamage(float Amount)
{
	if (Amount <= 0.f) return;
	CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth);
	if (CurrentHealth <= 0.f) OnPlayerDeath.Broadcast();
}

void URealHealthComponent::Heal(float Amount)
{
	if (Amount <= 0.f) return;
	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth);
}
	


// Called every frame
void URealHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

