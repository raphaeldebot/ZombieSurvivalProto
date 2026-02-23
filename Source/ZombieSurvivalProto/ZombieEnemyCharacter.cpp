#include "ZombieEnemyCharacter.h"
#include "ZombieAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AZombieEnemyCharacter::AZombieEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AZombieAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	//  IMPORTANT: le zombie tourne dans la direction où il marche
// IMPORTANT : on tourne via le controller (comme un vrai ennemi qui "fixe" sa cible)
// IMPORTANT: rotation pilotée par le controller (car on utilise SetFocus)
	bUseControllerRotationYaw = true;

	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);

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