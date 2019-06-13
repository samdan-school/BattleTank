// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTrack.h"
#include "TankMevementComponent.h"

void UTankMevementComponent::Initialize(UTankTrack* LeftTrack, UTankTrack* RightTrack)
{
	this->LeftTrack = LeftTrack;
	this->RightTrack = RightTrack;
}

void UTankMevementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);

	IntendMoveForward(ForwardThrow);
}

void UTankMevementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMevementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(1 * Throw);
	RightTrack->SetThrottle(-1.5 * Throw);
}

void UTankMevementComponent::IntendTurnLeft(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(-1.5 * Throw);
	RightTrack->SetThrottle(1 * Throw);
}
