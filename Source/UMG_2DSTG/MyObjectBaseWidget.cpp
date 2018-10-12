// Fill out your copyright notice in the Description page of Project Settings.

#include "MyObjectBaseWidget.h"

void UMyObjectBaseWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMyObjectBaseWidget::Move(float x, float y)
{
	float offsetX = size.X / 2;
	float offsetY = size.Y / 2;
	position.X += x;
	position.Y += y;

	this->SetRenderTranslation(position);
}

void UMyObjectBaseWidget::SetPosition(float x, float y)
{
	float offsetX = size.X / 2;
	float offsetY = size.Y / 2;
	position.X = x + offsetX;
	position.Y = y + offsetY;

	this->SetRenderTranslation(position);
}

FVector2D UMyObjectBaseWidget::GetPosition()
{
	return position;
}
