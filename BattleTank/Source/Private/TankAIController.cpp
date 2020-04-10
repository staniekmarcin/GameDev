// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    /* auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController cant find player tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
    } */
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());

    if (PlayerTank)
    {       
        //TODO move towards player

        //Aim towards the player
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
        ControlledTank->Fire(); //TODO limit firing rate    
    }
    
}




