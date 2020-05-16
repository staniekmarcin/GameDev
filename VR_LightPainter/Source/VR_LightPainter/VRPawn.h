// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"
#include "VRPawn.generated.h"

UCLASS()
class VR_LIGHTPAINTER_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	AVRPawn();

protected:
	virtual void BeginPlay() override;

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:

	void RightTriggerPressed() { if (RightPaintBrushHandController) RightPaintBrushHandController->TriggerPressed(); }
	void RightTriggerRealeased() { if (RightPaintBrushHandController) RightPaintBrushHandController->TriggerReleased(); }

	void Save();
	void Load();

	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> PaintBrushHandControllerClass;

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	// References
	UPROPERTY()
	AHandControllerBase* RightPaintBrushHandController;

	// State
	FString CurrentSlotName;
};
