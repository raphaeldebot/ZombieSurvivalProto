#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieEnemyCharacter.generated.h"

UCLASS()
class ZOMBIESURVIVALPROTO_API AZombieEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AZombieEnemyCharacter();

	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Zombie")
	float MaxHealth = 50.f;

	UPROPERTY(EditAnywhere, Category = "Zombie")
	float Damage = 10.f;

	UPROPERTY(EditAnywhere, Category = "Zombie")
	float AttackRange = 140.f;

	UPROPERTY(EditAnywhere, Category = "Zombie")
	float AttackCooldown = 1.2f;

private:
	float Health;
	float TimeSinceLastAttack = 0.f;

	void TryAttackPlayer(float DeltaSeconds);
};