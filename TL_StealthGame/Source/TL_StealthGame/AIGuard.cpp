


#include "AIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "TL_StealthGameGameMode.h"
#include "Kismet/GameplayStatics.h"

AAIGuard::AAIGuard()
{
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

	PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIGuard::OnPawnSeen);

}

void AAIGuard::BeginPlay()
{
	Super::BeginPlay();
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AAIGuard::OnNoiseHeard); // In BeginPlay cause some bug

	OriginRotation = GetActorRotation();
}

void AAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn == nullptr)
	{	
		return;
	}
	DrawDebugSphere(
		GetWorld(),
		SeenPawn->GetActorLocation(),
		32.0f,
		12, FColor::Yellow,
		false,
		10.0f
		);

	ATL_StealthGameGameMode* GM = Cast<ATL_StealthGameGameMode>(GetWorld()->GetAuthGameMode());
	if (GM)
	{
		GM->CompleteMission(SeenPawn, false);
	}
}

void AAIGuard::OnNoiseHeard(APawn* NoiseInstigator, const FVector& Location, float Volume)
{
	DrawDebugSphere(GetWorld(), Location, 32.0f, 12, FColor::Blue, false, 10.0f);
	UE_LOG(LogTemp, Log, TEXT("HEAR YOU"));

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();

	FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
	NewLookAt.Pitch = 0;
	NewLookAt.Roll = 0;

	SetActorRotation(NewLookAt);

	GetWorldTimerManager().ClearTimer(TimerHandle_ResetOrientation);
	GetWorldTimerManager().SetTimer(
		TimerHandle_ResetOrientation,
		this,
		&AAIGuard::ResetOrientation,
		3.0f
		);

}

void AAIGuard::ResetOrientation()
{
	SetActorRotation(OriginRotation);
}

void AAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



