

#include "PawnBase.h"

APawnBase::APawnBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	// Update TurretMesh rotation toface towards the LookAtTarget passed in from the child Class.
}

void APawnBase::Fire()
{
	// Spawn projectile at spawnpoint
}

void APawnBase::HandleDestruction()
{
	// Universal functionality
	// Play death effects, sounds, camera shake

	// ... Unigue child overirides
	// == Pawnturret - inform GameMode that turret died and detroy seld

	// PawnTank inform Gamemode Player Died ide all components and stop movement
	
}



