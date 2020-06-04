


#include "ExtractionZone.h"

#include "TL_StealthGameCharacter.h"
#include "TL_StealthGameGameMode.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"

AExtractionZone::AExtractionZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComp;

	OverlapComp->SetHiddenInGame(false);
	
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AExtractionZone::HandleOverlap);

	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(200.f, 200.f, 200.f);
	DecalComp->SetupAttachment(RootComponent);
}

void AExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Log, TEXT("Overlapped with extraction zone"));

	ATL_StealthGameCharacter* MyPawn = Cast<ATL_StealthGameCharacter>(OtherActor);
	if (MyPawn == nullptr)
	{
		return;
	}
	if (MyPawn->bIsCarryingObjective)
	{
		ATL_StealthGameGameMode* GM = Cast<ATL_StealthGameGameMode>(GetWorld()->GetAuthGameMode());
		if (GM)
		{
			GM->CompleteMission(MyPawn, true);
			UGameplayStatics::PlaySound2D(this, ObjectiveExtractedSound);
		}
	}
	else
	{
		
		UGameplayStatics::PlaySound2D(this, ObjectiveMissingSound);
	}

}


