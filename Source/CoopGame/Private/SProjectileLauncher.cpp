// Fill out your copyright notice in the Description page of Project Settings.


#include "SProjectileLauncher.h"
#include "SProjectile.h"

void ASProjectileLauncher::BeginPlay()
{
	Super::BeginPlay();
}

void ASProjectileLauncher::Fire()
{
	if (ProjectileClass)
	{
		FVector MuzzleLocation = MeshComp->GetSocketLocation("MuzzleSocket");
		FRotator MuzzleRotation = GetInstigatorController()->GetControlRotation();

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		ActorSpawnParams.Owner = this;

		AActor* actor = GetWorld()->SpawnActor<ASProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, ActorSpawnParams);
	}
}