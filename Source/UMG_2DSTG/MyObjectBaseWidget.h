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

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector2D position;

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector2D size;

	UPROPERTY(EditAnywhere, Category = "Movement")
		bool isGravity;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float gravitySpeed;

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void Move(float x, float y);

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void SetPosition(float x, float y);

	UFUNCTION(BlueprintPure, Category = "Movement")
		FVector2D GetPosition();

	UFUNCTION(BlueprintPure, Category = "Movement")
		FVector2D GetSize();

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void Gravity();

	UFUNCTION(BlueprintPure, Category = "Collision")
		bool IsHitTargetActor(FVector2D targetPos, FVector2D targetSize);

	UFUNCTION(BlueprintPure, Category = "Collision")
		bool IsOutViewport(float sizeX, float sizeY);
};
