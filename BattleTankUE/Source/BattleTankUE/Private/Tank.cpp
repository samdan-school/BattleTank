// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/AimComponent.h"
#include "Public/Tank.h"

// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AimComponent = CreateDefaultSubobject<UAimComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* Barrel) {
	this->AimComponent->SetBarrelReference(Barrel);
}

void ATank::SetTurrentReference(UTankTurrent* Turrent) {
	this->AimComponent->SetTurrentReference(Turrent);
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation) {
	this->AimComponent->AimAt(HitLocation, LaunchSpeed);
}
