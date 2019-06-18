// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimComponent.generated.h"

UENUM()
enum class EFiringStatus : uint8 {
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel; // Forwared Declaration
class UTankTurrent; // Forwared Declaration

// Hold barrel's properties and Elavate 
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKUE_API UAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAimComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BluePrintReadOnly, category = "State")
		EFiringStatus FiringState = EFiringStatus::Aiming;

private:
	UTankBarrel* Barrel = nullptr;

	UTankTurrent* Turrent = nullptr;

public:
	void SetBarrelReference(UTankBarrel* Barrel);

	void SetTurrentReference(UTankTurrent* Turrent);

private:
	void MoveBarrelTowards(FVector AimDirection);
};
