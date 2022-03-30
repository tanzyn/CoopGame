// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InnerMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InnerMeshComp"));
	OuterMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OuterMeshComp"));
	
	OuterMeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	InnerMeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	RootComponent = OuterMeshComp;
	InnerMeshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	InnerMeshComp->SetRelativeLocation(FVector(0));
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent*> OutActors;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	TArray< TEnumAsByte< EObjectTypeQuery > > ObjectTypes;

	UKismetSystemLibrary::SphereOverlapComponents(GetWorld(), GetActorLocation(), 50.0f, ObjectTypes, NULL, ActorsToIgnore, OutActors);

	for (UPrimitiveComponent* actor : OutActors)
	{
		actor->SetSimulatePhysics(true);
		
		actor->AddRadialForce(actor->GetRightVector(), 300.f, -8000.f, RIF_Linear, true);

		actor->AddRadialForce(GetActorLocation(), 30000.f, -8000.f, RIF_Linear, true);
	}
}

