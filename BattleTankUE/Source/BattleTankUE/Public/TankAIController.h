// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/Tank.h"
#include "Engine/World.h"

#include "TankAIController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANKUE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsPlayer() const;
};
