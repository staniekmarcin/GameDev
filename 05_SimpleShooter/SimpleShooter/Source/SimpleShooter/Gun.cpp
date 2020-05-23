

#include "Gun.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "ShooterCharacter.h"


AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);	

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	//UE_LOG(LogTemp,Warning,TEXT("SHOT"));
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return;
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) return;

	FVector AimLocation;
	FRotator AimRotation;
	OwnerController->GetPlayerViewPoint(AimLocation, AimRotation );
	//DrawDebugCamera(GetWorld(), AimLocation, AimRotation, 90, 2, FColor::Red, true);
	//DrawDebugPoint(GetWorld(), AimLocation, 20, FColor::Red, true);
	FVector End = AimLocation + AimRotation.Vector() * MaxRange;
	// TODO: LineTrace
	FHitResult Hit;
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, AimLocation, End, ECollisionChannel::ECC_GameTraceChannel1);
	if (bSuccess)
	{
		DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Red, true);
	}

}

void AGun::BeginPlay()
{
	Super::BeginPlay();

}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

