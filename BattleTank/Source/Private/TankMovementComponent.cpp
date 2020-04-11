// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    if(!LeftTrackToSet || !RightTrackToSet)
    {
        LeftTrack = LeftTrackToSet;
        RightTrack = RightTrackToSet;
    }
}
void UTankMovementComponent::IntendMoveForward(float Throw)
{
    //auto Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
    // TODO prevet double speed
    
}
