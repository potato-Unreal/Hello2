// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorChallenge.h"

// Sets default values
AMyActorChallenge::AMyActorChallenge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TArray<int> randomStep2() {
	TArray<int> ranPosition;
	ranPosition.Add(FMath::RandRange(0, 1));
	ranPosition.Add(FMath::RandRange(0, 1));
	return ranPosition;
}

TArray<int> eventRandJump() {
	TArray<int> ranJump;
	ranJump.Add(FMath::RandRange(-20, 20));
	ranJump.Add(FMath::RandRange(-20, 20));
	return ranJump;
}

void distance(int a, int b) {
	double temp = sqrt(a * a + b * b);
	UE_LOG(LogTemp, Log, TEXT("Move distance is %lf"), temp);
}

void moveTen2() {
	int positionX = 0;
	int positionY = 0;
	TArray<int> randArray;
	TArray<int> randjump;

	for (int i = 0; i < 10; i++) {
		randArray = randomStep2();
		positionX += randArray[0];
		positionY += randArray[1];

		UE_LOG(LogTemp, Warning, TEXT("[No. %d] Move to %d for X / Move to %d for Y."), i, randArray[0], randArray[1]);
		UE_LOG(LogTemp, Log, TEXT("Now Position --- X : %d / Y : %d ---"), positionX, positionY);
		distance(randArray[0], randArray[1]);

		if (FMath::RandRange(0, 1) == 1) {
			randjump = eventRandJump();
			positionX += randjump[0];
			positionY += randjump[1];

			UE_LOG(LogTemp, Warning, TEXT("What is this?!!?!!?!!!!?!! - you have set a trap, jump to %d, %d."), randjump[0], randjump[1]);
			UE_LOG(LogTemp, Log, TEXT("Now Position --- X : %d / Y : %d ---"), positionX, positionY);
			distance(randjump[0], randjump[1]);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("'This Location is safe!' - nothing happened."));
		}
	}
}

// Called when the game starts or when spawned
void AMyActorChallenge::BeginPlay()
{
	Super::BeginPlay();
	moveTen2();
}

// Called every frame
void AMyActorChallenge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

