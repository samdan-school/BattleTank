// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include "Engine/World.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank) { return; }

	MoveToActor(
		PlayerTank,
		30
	);

	//UE_LOG(LogTemp, Warning, TEXT("%s loc"), *PlayerTank->GetActorLocation().ToString());

	AimTowardsPlayer();
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::AimTowardsPlayer() const
{
	auto PlayerTank = GetPlayerTank();

	GetControlledTank()->AimAt(PlayerTank->GetActorLocation());

	GetControlledTank()->Fire();
}