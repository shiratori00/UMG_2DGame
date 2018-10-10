// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UMG_2DSTGEditorTarget : TargetRules
{
	public UMG_2DSTGEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "UMG_2DSTG" } );
	}
}
