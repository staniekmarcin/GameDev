

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "PawnTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

public:

    APawnTank();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
private:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* SpringArmComp;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* CameraComp;

protected:
    virtual void BeginPlay() override;

};
