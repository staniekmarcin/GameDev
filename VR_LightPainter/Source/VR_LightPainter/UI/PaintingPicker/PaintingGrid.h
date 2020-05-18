

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/UniformGridPanel.h"

#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class VR_LIGHTPAINTER_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddPainting(int32 PaintingIndex);
	
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel* PaintingGrid;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> GridCardClass;
};
