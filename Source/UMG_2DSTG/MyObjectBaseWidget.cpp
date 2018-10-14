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
	float offsetX = size.X / 2;
	float offsetY = size.Y / 2;
	//position.X = x + offsetX;
	//position.Y = y + offsetY;
	position.X = x;
	position.Y = y;

	this->SetRenderTranslation(position);
}

FVector2D UMyObjectBaseWidget::GetPosition()
{
	return position;
}

FVector2D UMyObjectBaseWidget::GetSize()
{
	return size;
}

void UMyObjectBaseWidget::Gravity()
{
	//重力を適用しない場合は処理をしない
	if (!isGravity) return;

	//位置フレームの重力での移動量を取得
	float deltaY = GWorld->DeltaTimeSeconds * gravitySpeed;

	//移動処理
	this->Move(0.0f, deltaY);

}

bool UMyObjectBaseWidget::IsHitTargetActor(FVector2D targetPos, FVector2D targetSize)
{
	float distanceX = FMath::Abs(targetPos.X - this->position.X);
	float distanceY = FMath::Abs(targetPos.Y - this->position.Y);
	float deltaSizeX = targetSize.X / 2 + this->size.X / 2;
	float deltaSizeY = targetSize.Y / 2 + this->size.Y / 2;

	//四角形の範囲内ならtrue
	if ((distanceX < deltaSizeX) && (distanceY < deltaSizeY))
	{
		return true;
	}
	return false;
}

bool UMyObjectBaseWidget::IsOutViewport(float sizeX, float sizeY)
{
	//trueなら範囲外
	if ((position.X < 0) || (position.X + size.X > sizeX) || (position.Y < 0) || (position.Y + size.Y > sizeY))
	{
		return true;
	}
	return false;
}
