// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKUE_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Editanywhere, Category = Setup)
		float MaxDegreesPerSecond = 10.f;

	void Rotate(float RelativeSpeed);
};
