#include "ZombieAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AZombieAIController::AZombieAIController()
{
	PrimaryActorTick.bCanEverTick = true; // <- indispensable pour que Tick tourne
}

void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AZombieAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TimeSinceLastUpdate += DeltaSeconds;
	if (TimeSinceLastUpdate < UpdateRate) return;
	TimeSinceLastUpdate = 0.f;

	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!Player) return;

	SetFocus(Player);                 // le zombie "regarde" le joueur
	MoveToActor(Player, AcceptanceRadius);
}