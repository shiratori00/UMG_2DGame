// Fill out your copyright notice in the Description page of Project Settings.

#include "MyObjectBaseWidget.h"

//�R���X�g���N�^�H
void UMyObjectBaseWidget::NativeConstruct()
{
	Super::NativeConstruct();	
}

//�ړ�����
void UMyObjectBaseWidget::Move(float x, float y)
{
	position.X += x;
	position.Y += y;

	this->SetRenderTranslation(position);
}

//�ʒu��ݒ�
void UMyObjectBaseWidget::SetPosition(float x, float y)
{
	position.X = x;
	position.Y = y;

	this->SetRenderTranslation(position);
}

//�ʒu���擾
FVector2D UMyObjectBaseWidget::GetPosition()
{
	return position;
}

//�T�C�Y���擾
FVector2D UMyObjectBaseWidget::GetSize()
{
	return size;
}

//�d�͏���
void UMyObjectBaseWidget::Gravity()
{
	//�d�͂�K�p���Ȃ��ꍇ�͏��������Ȃ�
	if (!isGravity) return;

	//�ʒu�t���[���̏d�͂ł̈ړ��ʂ��擾
	float deltaY = GWorld->DeltaTimeSeconds * gravitySpeed;

	//�ړ�����
	this->Move(0.0f, deltaY);

}

//�����蔻��
bool UMyObjectBaseWidget::IsHitTargetActor(FVector2D targetPos, FVector2D targetSize)
{
	float distanceX = FMath::Abs(targetPos.X - this->position.X);
	float distanceY = FMath::Abs(targetPos.Y - this->position.Y);
	float deltaSizeX = targetSize.X / 2 + this->size.X / 2;
	float deltaSizeY = targetSize.Y / 2 + this->size.Y / 2;

	//�l�p�`�͈͓̔��Ȃ�true
	if ((distanceX < deltaSizeX) && (distanceY < deltaSizeY))
	{
		return true;
	}

	return false;
}

//��ʊO�`�F�b�N����
bool UMyObjectBaseWidget::IsOutViewport(float sizeX, float sizeY)
{
	//true�Ȃ�͈͊O
	if ((position.X < 0) || (position.X + size.X > sizeX) || (position.Y < 0) || (position.Y + size.Y > sizeY))
	{
		return true;
	}

	return false;
}
