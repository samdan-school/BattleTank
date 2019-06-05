// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UAimComponent;
class AProjectile;
class UTankTurrent;

UCLASS()
class BATTLETANKUE_API ATank : public APawn {
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;

	UPROPERTY(EditAnywhere, Category = Setup)
		//UClass* ProjectileBlueprint; // Alternative TSubClass
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

public:
	void AimAt(FVector HitLocation);

protected:
	UAimComponent* AimComponent = nullptr;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* Barrel);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurrentReference(UTankTurrent* Turrent);

	UFUNCTION(BlueprintCallable, Category = Input)
		void Fire();

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
