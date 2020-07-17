// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(Words);

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{

    if (bGameOver) 
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking PlayerGuess
    {
        ProcessGuess(PlayerInput);
       
    }
    

}

void UBullCowCartridge::SetupGame()
{
    //Welcomeing the Player
    PrintLine(TEXT("Happy July 17th 8:57 am!"));

    HiddenWord = Isograms[FMath::RandRange(0,Isograms.Num()-1)]; 
    Lives = HiddenWord.Len(); 
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); //Debug line

    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue..."));
    
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("\nPress enter to continue."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{

    if (Guess == HiddenWord) 
    {
        PrintLine(TEXT("You win"));
        EndGame();
        return;
    }
    
    if (Guess.Len() != HiddenWord.Len()) 
    {
        PrintLine(TEXT("The Hidden Word is %i letters long!"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
        return;
    }

    //Check if it's an isogram
    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;

    }



    // Remove life
    --Lives;
    PrintLine(TEXT("You have lost a life"));
    
    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The Hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }

    // Show the player Bulls and cows
    FBullCowCount Score = GetBullCows(Guess);

    PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);

    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    
    // for (int32 Index = 0, Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
    // {   
    //     if (Word[Index]==Word[Comparison])
    //     {
    //         return false;
    //     }

    //     Index++;   
    // }

    for (int32 Index = 0; Index < Word.Len(); Index++)
    {   
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {   
            if (Word[Index]==Word[Comparison])
            {
                return false;
            } 
        }
    }

    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    // for (int32 Index =0; Index < WordList.Num(); Index++)
    // {
    //     if(WordList[Index].Len()>=4 && WordList[Index].Len()<=8 && IsIsogram(WordList[Index]))
    //     {
    //         ValidWords.Emplace(WordList[Index]);
    //     }
    // }

      for (FString Word : WordList)
    {
        if(Word.Len()>=4 && Word.Len()<=8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }

    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if(Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                Count.Cows++;
                break;
            }
        }

    }

    return Count;
    
}