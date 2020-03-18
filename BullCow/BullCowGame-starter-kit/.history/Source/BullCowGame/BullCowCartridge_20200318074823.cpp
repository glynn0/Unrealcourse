// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h" 



void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();
    
    // Welcome the Player

    PrintLine(TEXT("Welcome to my Bull Cows Game"));
    PrintLine(TEXT("Guess the 4 letter word"));
    PrintLine(TEXT("Input your name and Press ENTER"));
    
    // Setting up the Game
    HiddenWord = TEXT("cake"); // Set HiddenWord
    // Set Lives

    // Prompt Player for Guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    
    ClearScreen();
    
    PrintLine(Input);

    if (Input == HiddenWord)
    {
        PrintLine (TEXT("You Win"));
    }
    else
    {
        PrintLine (TEXT("You Lose"));
    }
    // Check if IsoGram
    // Check Right number of Characters
    
    // Remove Life
    // Check if Lives > 0
    // If Yes, GuessAgain
    // Show LivesLeft
    // If No, Show Game Over and HiddenWord?
    // Prompt to Play again Press Enter to Play Again
    // Check User Input
    // 
}