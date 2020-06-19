

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:

    virtual void BeginPlay() override;

public:

    void ActorDied(AActor* DeadActor);

    UFUNCTION(BlueprintImplementableEvent)
    void GameStart();
 
    UFUNCTION(BlueprintImplementableEvent)
    void GameOver();

    
private:
    void HandleGameStart();
    void HandleGameOver(bool PlayerWon);
};
