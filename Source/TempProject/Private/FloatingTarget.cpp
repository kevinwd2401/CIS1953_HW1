// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingTarget.h"

// Sets default values
AFloatingTarget::AFloatingTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	MeshComp->SetSimulatePhysics(false);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComp->SetCollisionProfileName("BlockAll");
	MeshComp->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void AFloatingTarget::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	MeshComp->OnComponentHit.AddDynamic(this, &AFloatingTarget::OnMeshHit);
}

// Called every frame
void AFloatingTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedTime += DeltaTime;
	FVector newHeight = StartLocation;
	newHeight.Z += FMath::Sin(ElapsedTime * FloatSpeed) * FloatAmplitude;
	SetActorLocation(newHeight);

	FRotator newRotation = GetActorRotation();
	newRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(newRotation);
}


void AFloatingTarget::OnMeshHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit)
{
		GEngine->AddOnScreenDebugMessage(
			-1,              // Key (-1 means "add new line")
			5.0f,            // Time to display (in seconds)
			FColor::Green,   // Text color
			TEXT("Change Location") // The message
		);
		
		RelocateTarget();

}

void AFloatingTarget::RelocateTarget()
{
	FVector currentLocation = GetActorLocation();

	float rX = FMath::RandRange(-TeleportRadius, TeleportRadius);
	float rY = FMath::RandRange(-TeleportRadius, TeleportRadius);

	FVector newLocation = currentLocation + FVector(rX, rY, 0.0);

	SetActorLocation(newLocation);
	StartLocation = StartLocation + FVector(rX, rY, 0.0);
}

