// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabbedItem.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"

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

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	check(WidgetComponent);
	WidgetComponent->SetupAttachment(StaticMeshComponent);
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	WidgetComponent->SetRelativeLocation(FVector(0.f, 100.f, 0.f));
}

void AGrabbedItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrabbedItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

