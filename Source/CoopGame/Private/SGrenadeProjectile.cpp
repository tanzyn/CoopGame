// Fill out your copyright notice in the Description page of Project Settings.


#include "SGrenadeProjectile.h"
#include "Components/PrimitiveComponent.h"
#include "SProjectileLauncher.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASGrenadeProjectile::ASGrenadeProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionResponseToAllChannels(ECR_Block);
}

// Called when the game starts or when spawned
void ASGrenadeProjectile::BeginPlay()
{
	Super::BeginPlay();
	MeshComp->AddImpulse(GetActorForwardVector() * ImpulseAmount, NAME_None, true);
	GetWorld()->GetTimerManager().SetTimer(ExplosionTimerHandle, this, &ASGrenadeProjectile::Explode, ExplodeDelay);
}

void ASGrenadeProjectile::Explode()
{
	ASProjectileLauncher* MyOwner = Cast<ASProjectileLauncher>(GetOwner());

	if (ExplosionEffect)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
	}

	if (ExplosionSoundEffect)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), ExplosionSoundEffect);
	}

	if (DamageType)
	{
		TArray<AActor*> IgnoreActors;
		IgnoreActors.Add(this);
		IgnoreActors.Add(MyOwner);
		UGameplayStatics::ApplyRadialDamage(GetWorld(), 10.0f, GetActorLocation(), 500.0f, DamageType, IgnoreActors);
	}

	Destroy();
}

// Called every frame
void ASGrenadeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

