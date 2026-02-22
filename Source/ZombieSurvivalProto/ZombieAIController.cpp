#include "ZombieAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AZombieAIController::AZombieAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
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

	// Le zombie regarde le joueur (rotation du controller)
	SetFocus(Player);

	// Le zombie se déplace vers le joueur (pathfinding)
	MoveToActor(Player, AcceptanceRadius);
}