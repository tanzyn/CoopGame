// Fill out your copyright notice in the Description page of Project Settings.


#include "SGrenadeLauncher.h"
#include "SGrenadeProjectile.h"

void ASGrenadeLauncher::BeginPlay()
{
	Super::BeginPlay();
}

void ASGrenadeLauncher::Fire()
{
	if (ProjectileClass)
	{
		FVector MuzzleLocation = MeshComp->GetSocketLocation("MuzzleSocket");
		FRotator MuzzleRotation = MeshComp->GetSocketRotation("MuzzleSocket");

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		AActor* actor = GetWorld()->SpawnActor<ASGrenadeProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, ActorSpawnParams);
	}
}