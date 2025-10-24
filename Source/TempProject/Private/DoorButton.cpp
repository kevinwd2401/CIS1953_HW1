// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorButton.h"
#include "HingeDoor.h"

// Sets default values
ADoorButton::ADoorButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	doorOpen = false;
}

// Called when the game starts or when spawned
void ADoorButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorButton::ButtonPress() {
	if (!TargetDoor) return;

	if (doorOpen)
	{
		TargetDoor->CloseDoor();
	}
	else
	{
		TargetDoor->OpenDoor();
	}
	doorOpen = !doorOpen;
}

