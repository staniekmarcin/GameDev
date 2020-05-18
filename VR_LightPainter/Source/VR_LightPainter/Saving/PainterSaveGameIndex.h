

//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/SaveGame.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "PainterSaveGame.h"

#include "PainterSaveGameIndex.generated.h"

/**
 *
 */
UCLASS()
class VR_LIGHTPAINTER_API UPainterSaveGameIndex : public USaveGame
{
	GENERATED_BODY()

public:
	static UPainterSaveGameIndex* Load();
	bool Save();

	void AddSaveGame(UPainterSaveGame* SaveGame);
	TArray<FString> GetSlotNames() const { return SlotNames; }

private:
	static const FString SLOT_NAME;

	UPROPERTY()
		TArray<FString> SlotNames;

};
