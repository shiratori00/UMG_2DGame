// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyObjectBaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class UMG_2DSTG_API UMyObjectBaseWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, Category = "Edit")
		FVector2D position;

	UPROPERTY(EditAnywhere, Category = "Edit")
		FVector2D size;

	UFUNCTION(BlueprintCallable, Category = "ObjectMovement")
		void Move(float x, float y);

	UFUNCTION(BlueprintCallable, Category = "ObjectMovement")
		void SetPosition(float x, float y);

	UFUNCTION(BlueprintPure, Category = "ObjectMovement")
		FVector2D GetPosition();
};
