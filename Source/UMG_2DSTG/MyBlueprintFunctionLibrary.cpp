// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"

TArray<FString> UMyBlueprintFunctionLibrary::FileLoadAndReturnString(FString FileName)
{
	TArray<FString> myString;
	bool myBool = true;

	myBool = FFileHelper::LoadFileToStringArray(myString, *(FPaths::GameDir() + FileName));

	return myString;
}


