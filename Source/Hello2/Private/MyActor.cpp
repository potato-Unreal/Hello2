// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TArray<int> randomStep() {
	TArray<int> ranPosition;
	ranPosition.Add(FMath::RandRange(0, 1));
	ranPosition.Add(FMath::RandRange(0, 1));
	return ranPosition;
}

void moveTen() {
	int positionX = 0;
	int positionY = 0;
	TArray<int> randArray;

	for (int i = 0; i < 10; i++) {
		randArray = randomStep();
		positionX += randArray[0];
		positionY += randArray[1];
		UE_LOG(LogTemp, Warning, TEXT("[No. %d] Move to %d for X / Move to %d for Y."), i, randArray[0], randArray[1]);
		UE_LOG(LogTemp, Log, TEXT("Now Position --- X : %d / Y : %d ---"), positionX, positionY);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	moveTen();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

