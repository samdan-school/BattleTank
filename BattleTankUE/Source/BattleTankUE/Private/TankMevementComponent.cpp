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

	auto RightThrow = FVector::CrossProduct(AIForwardIntention, TankForward);
	if (RightThrow.Z > 0.0f)
	{
		IntendTurnRight(1);
	}
	else
	{
		IntendTurnRight(-1);
	}
}

void UTankMevementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	UE_LOG(LogTemp, Warning, TEXT("Throw %f"), Throw);
}

void UTankMevementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	if (Throw > 0.0f)
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(-2 * Throw);
	}
	else
	{
		LeftTrack->SetThrottle(2 * Throw);
		RightTrack->SetThrottle(-Throw);
	}
}