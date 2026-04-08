// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WitchCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AWitchCharacter::AWitchCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;//将角色朝向旋转至移动方向
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);//旋转速度
	GetCharacterMovement()->bConstrainToPlane = true;//移动限制在平面
	GetCharacterMovement()->bSnapToPlaneAtStart = true;//开始时确保角色在地面
	
	bUseControllerRotationPitch = false;//不使用控制器旋转
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
