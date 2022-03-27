// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SProjectileLauncher.generated.h"

/**
 * 
 */
class ASProjectile;
UCLASS()
class COOPGAME_API ASProjectileLauncher : public ASWeapon
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	virtual void Fire() override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ASProjectile> ProjectileClass;
};
