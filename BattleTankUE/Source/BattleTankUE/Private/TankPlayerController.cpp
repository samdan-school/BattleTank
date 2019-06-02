// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s."), *((ControlledTank->GetName())));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

// Tick
	// Super
	// AimTowardsCrosshair()
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out parameter

		// Tell controlled tanl to aim to the point
	if (GetSightRayHitLocation(OutHitLocation))
	{
		this->GetControlledTank()->AimAt(OutHitLocation);
	}
}

// Get world location if linetrace throug crosshair If it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// find the crosshair position  in pixel coordinates
	bool HitLandscape = false;

	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(OUT ViewPortSizeX, OUT ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation);

	FVector LookDirection;

	// De-project the screen position of the croosshair to a world direction
		// If not found return

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction and see what we hit up to max range
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		HitLandscape = true;
	}

	return HitLandscape;
}

bool ATankPlayerController::GetLookVectorHitLocation(const FVector& LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * this->LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	)) {
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0.f);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		OUT WorldLocation,
		OUT LookDirection
	);
}
