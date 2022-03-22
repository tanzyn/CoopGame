// Fill out your copyright notice in the Description page of Project Settings.


#include "SGrenadeProjectile.h"

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
	
}

// Called every frame
void ASGrenadeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

