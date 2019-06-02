// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/AimComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Public/TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UAimComponent::SetBarrelReference(UTankBarrel* Barrel)
{
	this->Barrel = Barrel;
}

void UAimComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity = FVector(0.f);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UAimComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work out difference between current barrel reation and aim Direction
	auto BarrelRotaion = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotaion;

	// Move the barrel the right amount this frame
	// Given a max elevation

	Barrel->Elevate(5);
}