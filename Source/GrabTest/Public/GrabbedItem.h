// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "GrabbedItem.generated.h"

class USphereComponent;
class UUserWidget;
class UWidgetComponent;

UCLASS()
class GRABTEST_API AGrabbedItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabbedItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Mesh)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Mesh)
	USphereComponent* SphereInteract;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Mesh)
	UWidgetComponent* WidgetComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
