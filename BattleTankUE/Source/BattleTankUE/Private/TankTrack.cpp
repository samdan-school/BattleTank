// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float throttle)
{
	const auto ForceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	const auto ForceLocation = GetComponentLocation();
	const auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}