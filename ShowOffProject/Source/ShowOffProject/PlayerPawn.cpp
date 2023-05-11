// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FVector APlayerPawn::ClampRotation()
{
	float xRot = GetActorTransform().GetRotation().GetRotationAxis().X;
	float yRot = GetActorTransform().GetRotation().GetRotationAxis().Y;

	if (xRot >= maxRot)
	{
		return FVector(maxRot - xRot, 0, 0);
	}
	else if(xRot <= maxRot)
	{
		return FVector(xRot - maxRot, 0, 0);
	}

	if (yRot >= minRot)
	{
		return FVector(0, minRot - yRot, 0);
	}
	else if (yRot <= minRot)
	{
		return FVector(0, yRot - minRot, 0);
	}

	return FVector(0, 0, 0);
}
