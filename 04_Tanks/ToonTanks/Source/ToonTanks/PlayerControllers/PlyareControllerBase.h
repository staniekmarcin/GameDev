

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlyareControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlyareControllerBase : public APlayerController
{
	GENERATED_BODY()
	
	public:
	
	void SetPlayerEnabledState(bool SetPlayerEnabled);
	
};
