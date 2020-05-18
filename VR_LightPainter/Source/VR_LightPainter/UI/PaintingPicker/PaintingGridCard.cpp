


#include "PaintingGridCard.h"

#include "Kismet/GameplayStatics.h"

void UPaintingGridCard::SetPaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;

	SlotName->SetText(FText::FromString(PaintingName));

	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::CardButtonClicked);
}

void UPaintingGridCard::CardButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("TestMap"), true, "SlotName = " + PaintingName );
}