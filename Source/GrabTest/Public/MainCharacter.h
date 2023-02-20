// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class AGrabbedItem;

UCLASS()
class GRABTEST_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void Right(float Value);
	virtual void Forward(float Value);
	virtual void Grab();
	
	UFUNCTION()
	virtual void BeginOverlapWithItem(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	virtual void EndOverlapWithItem(AActor* OverlappedActor, AActor* OtherActor);

	AActor* OverlappedActor = nullptr;
	AGrabbedItem* GrabbedActor = nullptr;
	bool bIsGrabbed = false;
};
