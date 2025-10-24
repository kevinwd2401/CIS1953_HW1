// Fill out your copyright notice in the Description page of Project Settings.


#include "HingeDoor.h"

// Sets default values
AHingeDoor::AHingeDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rotateDoor = false;
}

// Called when the game starts or when spawned
void AHingeDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHingeDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (rotateDoor)
	{
		FRotator currRotation = GetActorRotation();
		currRotation.Yaw += turnSpeed * DeltaTime;
		SetActorRotation(currRotation);
		if ((turnSpeed > 0 && currRotation.Yaw > 90) || (turnSpeed < 0 && currRotation.Yaw < 0)) {
			rotateDoor = false;
		}
	}
}


void AHingeDoor::OpenDoor() {
	rotateDoor = true;
	turnSpeed = 90.0;

}

void AHingeDoor::CloseDoor() {
	rotateDoor = true;
	turnSpeed = -90.0;
}
