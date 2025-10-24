// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DoorInteractionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TEMPPROJECT_API UDoorInteractionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "DoorInteraction")
	static void TryPressDoorButton(UObject* WorldContextObject, FVector StartPos, FVector Direction, float TraceDistance = 500.f);
};
