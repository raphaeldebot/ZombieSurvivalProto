#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ZombieAIController.generated.h"

UCLASS()
class ZOMBIESURVIVALPROTO_API AZombieAIController : public AAIController
{
	GENERATED_BODY()

public:
	AZombieAIController();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "AI")
	float UpdateRate = 0.2f;

	UPROPERTY(EditAnywhere, Category = "AI")
	float AcceptanceRadius = 120.f;

private:
	float TimeSinceLastUpdate = 0.f;
};