// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKUE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
		/// propertities
private:
	// Max force drive per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 100000000; // assume 40 ton tank, and 1g acceleration


		/// Methods
public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float throttle);
};
