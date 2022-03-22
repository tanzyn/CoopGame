// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGrenadeProjectile.generated.h"

UCLASS()
class COOPGAME_API ASGrenadeProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASGrenadeProjectile();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
