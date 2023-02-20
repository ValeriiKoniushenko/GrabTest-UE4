// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MainHUD.h"
#include "GrabbedItem.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ThisClass::BeginOverlapWithItem);
	OnActorEndOverlap.AddDynamic(this, &ThisClass::EndOverlapWithItem);
}

void AMainCharacter::BeginOverlapWithItem(AActor* CurrentOverlappedActor, AActor* OtherActor)
{
	AMainHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AMainHUD>();
	HUD->ToggleInteractWidget();
	OverlappedActor = OtherActor;
}

void AMainCharacter::EndOverlapWithItem(AActor* CurrentOverlappedActor, AActor* OtherActor)
{
	AMainHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AMainHUD>();
	HUD->ToggleInteractWidget();
	OverlappedActor = nullptr;
}

void AMainCharacter::Right(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMainCharacter::Forward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GrabbedActor)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.Y += 100.f;
		NewLocation.X += 100.f;
		GrabbedActor->SetActorLocation(NewLocation);
	}
}

void AMainCharacter::Grab()
{
	if (bIsGrabbed)
	{
		AGrabbedItem* Item = Cast<AGrabbedItem>(OverlappedActor);
		if (Item)
		{
			Item->StaticMeshComponent->SetSimulatePhysics(false);
			GrabbedActor = Item;
		}
	}
	else
	{
		if (GrabbedActor)
		{
			GrabbedActor->StaticMeshComponent->SetSimulatePhysics(true);
		}
		
		GrabbedActor = nullptr;
	}
	
	bIsGrabbed = !bIsGrabbed;
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &ThisClass::Forward);
	PlayerInputComponent->BindAxis("Right", this, &ThisClass::Right);
	PlayerInputComponent->BindAxis("LookUp", this, &ThisClass::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookAround", this, &ThisClass::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ThisClass::Jump);
	PlayerInputComponent->BindAction("Grab", IE_Pressed, this, &ThisClass::Grab);
	PlayerInputComponent->BindAction("Grab", IE_Released, this, &ThisClass::Grab);
}

