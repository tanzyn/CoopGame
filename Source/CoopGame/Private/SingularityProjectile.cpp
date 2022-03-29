// Fill out your copyright notice in the Description page of Project Settings.


#include "SingularityProjectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BlackHole.h"
#include "SProjectileLauncher.h"

// Sets default values
ASingularityProjectile::ASingularityProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetEnableGravity(false);
	MeshComp->SetCollisionResponseToAllChannels(ECR_Block);
	MeshComp->SetNotifyRigidBodyCollision(true);

	CollisionSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphereComp"));
}

// Called when the game starts or when spawned
void ASingularityProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComp->AddImpulse(GetActorForwardVector() * ImpulseAmount, NAME_None, true);
	MeshComp->OnComponentHit.AddDynamic(this, &ASingularityProjectile::CollapseIntoBlackhole);
}

// Called every frame
void ASingularityProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASingularityProjectile::CollapseIntoBlackhole(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
	if (ProjectileClass)
	{
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		
		GetWorld()->SpawnActor<ABlackHole>(ProjectileClass, GetActorLocation(), GetActorRotation(), ActorSpawnParams);
	}
}

