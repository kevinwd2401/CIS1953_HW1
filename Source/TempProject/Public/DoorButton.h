// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorButton.generated.h"

class AHingeDoor;

UCLASS()
class TEMPPROJECT_API ADoorButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorButton();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	bool doorOpen;

	// Reference to the door, assignable in editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	AHingeDoor* TargetDoor;

	// Call this to trigger the door
	UFUNCTION(BlueprintCallable, Category = "Door")
	void ButtonPress();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
