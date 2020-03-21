// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

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
    PrintLine(TEXT("\nPress Enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You Win"));
        EndGame();
        return;
    }

if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i remaining"), Lives);
        PrintLine(TEXT("The Hidden word is %i letters long"), HiddenWord.Len());
        return;
    }

    //Check if Isogram

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }
PrintLine(TEXT("Lost a life!"));
--Lives;

if (Lives <= 0)
{
    ClearScreen();
    PrintLine(TEXT("You have no lives left!"));
    PrintLine(TEXT("The Hidden Word was: %s"), *HiddenWord);
    EndGame();
    return;
}

PrintLine(TEXT("Guess again, you have %i lives remaining."), Lives);
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    // int32 Index = 0;
    // int32 Comparison = Index + 1;


        for (int32 Index = 0; Index < Word.Len(); Index++)
        {
            for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
            {
                if (Word[Index] == Word[Comparison])
                {
                    return false;
                }
            }
            
        }
        

    return true;
    
}