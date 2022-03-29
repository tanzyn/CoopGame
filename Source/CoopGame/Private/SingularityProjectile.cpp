// Fill out your copyright notice in the Description page of Project Settings.


#include "SingularityProjectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
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

	CollisionSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphereComp"));

	MeshComp->OnComponentHit.AddDynamic(this, &ASingularityProjectile::CollapseIntoBlackhole);
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

void ASingularityProjectile::CollapseIntoBlackhole(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ASProjectileLauncher* MyOwner = Cast<ASProjectileLauncher>(GetOwner());

	TArray<AActor*> OverlappingActors;
	CollisionSphereComp->GetOverlappingActors(OverlappingActors, ClassFilter);

	for (auto& actor : OverlappingActors)
	{
		TArray<AActor*> IgnoreActors;
		IgnoreActors.Add(this);
		IgnoreActors.Add(MyOwner);
		UGameplayStatics::ApplyRadialDamage(GetWorld(), 10.0f, actor->GetActorLocation(), 500.0f, DamageType, IgnoreActors);
	}
}

