// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();

    FBullCount Count;
 

    IsoGrams = GetValidWords(Words);

    SetupGame();

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

    
}

void UBullCowCartridge::SetupGame()
{
    //PrintLine(TEXT("There are %i possible words."), Words.Num());
    //PrintLine(TEXT("There are %i valid words"), GetValidWords(Words).Num());

    HiddenWord = IsoGrams[FMath::RandRange(0, IsoGrams.Num() - 1)];
    Lives = HiddenWord.Len() * 2;
    bGameOver = false;

    // Welcome the Player 
    PrintLine(TEXT("Welcome to my Bull Cows Game"));
    PrintLine(TEXT("The Hidden Word is: %s"), *HiddenWord);
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives left."), Lives);
    
    PrintLine(TEXT("Type in your guess\nPress ENTER to continue")); // Prompt Player for Guess
    return;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress Enter to play again"));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
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

    //Show the player Bulls and Cows
    int32 Bulls, Cows;
    GetBullCows(Guess, );

    PrintLine(TEXT("You have %i Bulls and %i Cows"), Bulls, Cows);
    PrintLine(TEXT("Guess again, you have %i lives remaining."), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
 
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

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList ) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList )
    {
        if ((Word.Len() >= 4 && Word.Len() <= 8) && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);

        }
    }
    
   return ValidWords;
}
void UBullCowCartridge::GetBullCows(const FString &Guess, int32 &BullCount, int32 &CowCount) const
{
    
    BullCount = 0;
    CowCount = 0;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            BullCount++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                CowCount++;
                break;
            }
        }   
    }
    
}