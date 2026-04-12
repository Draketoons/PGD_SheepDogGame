// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Character/DogCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ADogCharacter::ADogCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Create Spring arm
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->bUsePawnControlRotation = true;
	
	//Create Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
	
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	
}

// Called when the game starts or when spawned
void ADogCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADogCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADogCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Bind Move Function to move input action
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADogCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADogCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ADogCharacter::Jump);
	}

}

void ADogCharacter::Move(const FInputActionValue& value)
{
	const FVector2D Axis = value.Get<FVector2D>();

	if (Controller && !Axis.IsZero())
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector ForwardDir =FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(ForwardDir, Axis.Y * MovementSpeed);
		AddMovementInput(RightDir, Axis.X * MovementSpeed);
		AddControllerYawInput(Axis.X);
		
	}
}

void ADogCharacter::Look(const FInputActionValue& value)
{
	FVector2D Axis = value.Get<FVector2D>();
	
	if (Controller && !Axis.IsZero())
	{
		//AddControllerYawInput(Axis.X);
		AddControllerPitchInput(Axis.Y);
	}
}

void ADogCharacter::Jump(const FInputActionValue& value)
{
	ACharacter::Jump();
}


