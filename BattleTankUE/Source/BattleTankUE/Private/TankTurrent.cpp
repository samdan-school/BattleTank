// Fill out your copyright notice in the Description page of Project Settings.

#include <TankTurrent.h>


void UTankTurrent::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	const auto RotationChange = RelativeSpeed * 100 * GetWorld()->DeltaTimeSeconds;
	const auto NewRotaion = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotaion, 0));
}