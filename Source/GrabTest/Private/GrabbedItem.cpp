// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabbedItem.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"

AGrabbedItem::AGrabbedItem()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));\
	check(StaticMeshComponent);
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetSimulatePhysics(true);

	SphereInteract = CreateDefaultSubobject<USphereComponent>(TEXT("InteractField"));
	check(SphereInteract);
	SphereInteract->SetupAttachment(RootComponent);
}

void AGrabbedItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrabbedItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

