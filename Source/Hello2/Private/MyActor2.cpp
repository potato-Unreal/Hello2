// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	TArray<int> randomNum;

	for (int i = 0; i < 6; i++) {
		int rand = FMath::RandRange(1, 45);
		if (randomNum.Contains(rand) == false) {
			randomNum.Add(rand);
		}
		else {
			i--;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("This is Lotto Number, [%d, %d, %d, %d, %d, %d] congratulations!"), randomNum[0], randomNum[1], randomNum[2], randomNum[3], randomNum[4], randomNum[5]);
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

