// Marcin Staniek Game Dev Course 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declaration
class UTankBarrel;
class UTankTurret;

//Hold barrel's properties and elevate method
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel *BarrelToSet);

	void SetTurretReference(UTankTurret *TurretToSet);

public:

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel *Barrel = nullptr;

	UTankTurret *Turret = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);
};
