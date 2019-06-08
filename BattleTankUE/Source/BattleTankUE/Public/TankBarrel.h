// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankBarrel.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKUE_API UTankBarrel : public UStaticMeshComponent {
	GENERATED_BODY()

public:
	UPROPERTY(Editanywhere, Category = Setup)
		float MaxDegreesPerSecond = 10.f;
	UPROPERTY(Editanywhere, Category = Setup)
		float MaxElevationDegrees = 40.f;
	UPROPERTY(Editanywhere, Category = Setup)
		float MinElevationDegrees = 0.f;

	void Elevate(float RelativeSpeed);

private:
};
