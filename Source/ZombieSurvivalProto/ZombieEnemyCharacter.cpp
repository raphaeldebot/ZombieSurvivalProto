#include "ZombieEnemyCharacter.h"
#include "ZombieAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AZombieEnemyCharacter::AZombieEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Important : dire que ce pawn utilise notre AIController
	AIControllerClass = AZombieAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	Health = MaxHealth;
}

void AZombieEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
}

void AZombieEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TryAttackPlayer(DeltaSeconds);
}

void AZombieEnemyCharacter::TryAttackPlayer(float DeltaSeconds)
{
	TimeSinceLastAttack += DeltaSeconds;

	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!Player) return;

	const float Dist = FVector::Dist(Player->GetActorLocation(), GetActorLocation());
	if (Dist > AttackRange) return;

	if (TimeSinceLastAttack < AttackCooldown) return;
	TimeSinceLastAttack = 0.f;

	// Pour l’instant : on log juste (on ajoutera la vie du joueur après)
	UE_LOG(LogTemp, Warning, TEXT("Zombie attacks! Damage = %f"), Damage);
}