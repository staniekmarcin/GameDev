


#include "TankGameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "ToonTanks/PawnTurret.h"

void ATankGameModeBase::BeginPlay()
{
    // Get references and game win/lose conditions.

    // Call HandleGameStart to initialise the start countdown, turret activation, pawn check etc.

    TargetTurrets = GetTargetTurrets();

    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));


    PlayerControllerRef = Cast<APlyareControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
    HandleGameStart();
    
    Super::BeginPlay();
}

int32 ATankGameModeBase::GetTargetTurrets()
{
    TSubclassOf<APawnTurret> ClassToFind;
    ClassToFind = APawnTurret::StaticClass();
    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, TurretActors);

    return TurretActors.Num();
}

void ATankGameModeBase::ActorDied(AActor *DeadActor)
{
	// UE_LOG(LogTemp, Warning, TEXT("An Actor died"));

    if (DeadActor == PlayerTank)
    {
        PlayerTank->PawnDestroyed();
        HandleGameOver(false);

        if (PlayerControllerRef)
        {
            PlayerControllerRef->SetPlayerEnabledState(false);
            
        }
    }
    else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
    {
        DestroyedTurret->PawnDestroyed();

        TargetTurrets--;

        if (TargetTurrets == 0)
        {
            HandleGameOver(true);
        }
    }
}



void ATankGameModeBase::HandleGameStart()
{
   GameStart();

    if (PlayerControllerRef)
    {
        PlayerControllerRef->SetPlayerEnabledState(true);

        FTimerHandle PlayerEnabledHandle;
        FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(PlayerControllerRef, &APlyareControllerBase::SetPlayerEnabledState, true);

        GetWorldTimerManager().SetTimer(PlayerEnabledHandle, PlayerEnableDelegate, StartDelay, false);
    }
} 

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
    GameOver(PlayerWon);
}

