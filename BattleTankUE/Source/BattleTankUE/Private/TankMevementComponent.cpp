// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTrack.h"
#include "TankMevementComponent.h"

void UTankMevementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMevementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	float RightConst = 1;
	float LeftConst = -1.5;

	if (Throw < 0.0f) {
		RightConst = -1.5;
		LeftConst = 1;
	}

	LeftTrack->SetThrottle(RightConst * Throw);
	RightTrack->SetThrottle(LeftConst * Throw);
}

void UTankMevementComponent::Initialize(UTankTrack* LeftTrack, UTankTrack* RightTrack)
{
	this->LeftTrack = LeftTrack;
	this->RightTrack = RightTrack;
}
