

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExtractionZone.generated.h"

class UBoxComponent;

UCLASS()
class TL_STEALTHGAME_API AExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	AExtractionZone();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent* DecalComp;
	
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
    USoundBase* ObjectiveExtractedSound;
	
	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	USoundBase* ObjectiveMissingSound;
	
};