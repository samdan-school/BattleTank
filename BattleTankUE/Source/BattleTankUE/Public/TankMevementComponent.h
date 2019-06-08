// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMevementComponent.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANKUE_API UTankMevementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

		/// Methods
public:
	UFUNCTION(BlueprintCallable)
		void IntendMoveForward(float Throw);
};
