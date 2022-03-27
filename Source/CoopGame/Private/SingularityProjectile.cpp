// Fill out your copyright notice in the Description page of Project Settings.


#include "SingularityProjectile.h"

// Sets default values
ASingularityProjectile::ASingularityProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetEnableGravity(false);
	MeshComp->SetCollisionResponseToAllChannels(ECR_Block);
}

// Called when the game starts or when spawned
void ASingularityProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComp->AddImpulse(GetActorForwardVector() * ImpulseAmount, NAME_None, true);
}

// Called every frame
void ASingularityProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

