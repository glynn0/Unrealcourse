// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();

    SetupGame();
    //PrintLine(TEXT("The codeword is --> %s\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());
}  

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Check Player Guess.
    {
        ProcessGuess(Input);
    }
    

    

    // Check if IsoGram
    // Prompt to Guess Again
    // Check Right number of Characters
    // Prompt to Guess Again
    // Remove Life
    // Check if Lives > 0
    // If Yes, GuessAgain
    // Show LivesLeft
    // If No, Show Game Over and HiddenWord?
    // Prompt to Play again Press Enter to Play Again
    // Check User Input
    // Play Again or Quit
}

void UBullCowCartridge::SetupGame()
{
    
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;

    // Welcome the Player
    PrintLine(TEXT("Welcome to my Bull Cows Game"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives left."), Lives);
    PrintLine(TEXT("Type in your guess\nPress ENTER to continue")); // Prompt Player for Guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
if (Guess == HiddenWord)
        {
        PrintLine(TEXT("You Win"));
        EndGame();
        }
        else
        {
            
            PrintLine(TEXT("Lost a life! -- %i lives remaining"), --Lives);
            if (Lives > 0)
            {
                if (Guess.Len() != HiddenWord.Len())
                {
                PrintLine(TEXT("Sorry, Try Guessing Again!\nYou have %i Lives remaining"), Lives);
                }
            }
            else
            {
                PrintLine(TEXT("You have run out of lives!!!"));
                EndGame();
            }
            

        }
}