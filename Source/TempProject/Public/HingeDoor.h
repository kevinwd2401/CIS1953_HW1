// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HingeDoor.generated.h"

UCLASS()
class TEMPPROJECT_API AHingeDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHingeDoor();

	UFUNCTION(BlueprintCallable, Category = "Door")
	void OpenDoor();

	UFUNCTION(BlueprintCallable, Category = "Door")
	void CloseDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool rotateDoor;
	float turnSpeed;
};
