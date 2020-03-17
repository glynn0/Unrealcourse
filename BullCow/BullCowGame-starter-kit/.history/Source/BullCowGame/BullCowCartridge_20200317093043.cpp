// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();
    PrintLine(TEXT("Welcome to my Bull Cows Game"));
    PrintLine(TEXT("Input your name and Press ENTER"));
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    
    ClearScreen();
    FString HiddenWord = TEXT("cake");
    PrintLine(Input);

    if (Input == HiddenWord)
    {
        /* code PrintLine (TEXT("You Win"));
    }
    else
    {
        PrintLine (TEXT("You Lose"));
    }
    
    
    
    
}