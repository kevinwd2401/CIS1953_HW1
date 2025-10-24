// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionLibrary.h"
#include "DoorButton.h"

UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
void UDoorInteractionLibrary::TryPressDoorButton(UObject* WorldContextObject, FVector StartPos, FVector Direction, float TraceDistance)
{
    if (!WorldContextObject) return;

    UWorld* World = WorldContextObject->GetWorld();
    if (!World) return;

    FVector EndPos = StartPos + Direction * TraceDistance;

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.bTraceComplex = true;

    bool bHit = World->LineTraceSingleByChannel(
        HitResult,
        StartPos,
        EndPos,
        ECC_Visibility,
        Params
    );


    if (bHit)
    {
        AActor* HitActor = HitResult.GetActor();
        if (HitActor)
        {
            ADoorButton* Button = Cast<ADoorButton>(HitActor);
            if (Button)
            {
                Button->ButtonPress();
            }
        }
    }
}