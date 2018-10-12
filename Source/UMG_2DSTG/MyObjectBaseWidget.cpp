// Fill out your copyright notice in the Description page of Project Settings.

#include "MyObjectBaseWidget.h"

void UMyObjectBaseWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMyObjectBaseWidget::Move(float x, float y)
{
	position.X += x;
	position.Y += y;

	this->SetRenderTranslation(position);
}

void UMyObjectBaseWidget::SetPosition(float x, float y)
{
	position.X = x;
	position.Y = y;

	this->SetRenderTranslation(position);
}
