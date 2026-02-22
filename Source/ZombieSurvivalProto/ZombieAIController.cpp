#include "ZombieAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(true);
}

void AZombieAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TimeSinceLastUpdate += DeltaSeconds;
	if (TimeSinceLastUpdate < UpdateRate) return;
	TimeSinceLastUpdate = 0.f;

	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!Player) return;

	MoveToActor(Player, /*AcceptanceRadius*/ 120.f);
}