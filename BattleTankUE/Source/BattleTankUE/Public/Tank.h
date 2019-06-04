// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UAimComponent;
class UTankBarrel;
class UTankTurrent;

UCLASS()
class BATTLETANKUE_API ATank : public APawn {
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 120000;

public:
	void AimAt(FVector HitLocation);

protected:
	UAimComponent* AimComponent = nullptr;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* Barrel);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurrentReference(UTankTurrent* Turrent);

protected:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
