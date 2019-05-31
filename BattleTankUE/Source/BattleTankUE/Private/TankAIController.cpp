// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not found player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found player tank %s"), *(PlayerTank->GetName()));
	}
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

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsPlayer();
}

void ATankAIController::AimTowardsPlayer() const
{
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank) { return; }

	GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
}
