// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define OUT

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANKUE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 150000.f;

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// Start the tank moving the barrel so that a shot would it where the crosshair intersetcs the world
	void AimTowardsCrosshair();

	// 
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	// 
	bool GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const;
};
