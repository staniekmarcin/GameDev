// Marcin Staniek Game Dev Course 2020

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //new incldues above

// Forward declarations

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	// Sets default values for this pawn's properties
	ATank();
};
