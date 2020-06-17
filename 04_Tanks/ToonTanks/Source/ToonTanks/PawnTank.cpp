


#include "PawnTank.h"

APawnTank::APawnTank()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArmComp);
}

void APawnTank::BeginPlay()
{
	Super::BeginPlay();
	
}

void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}