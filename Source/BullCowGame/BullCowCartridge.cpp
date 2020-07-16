// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    GetValidWords(Words);
    SetupGame();

    PrintLine(TEXT("The number of valid words is: %i"), GetValidWords(Words).Num());
    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); //Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    if (bGameOver) 
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking PlayerGuess
    {
        ProcessGuess(Input);
       
    }
    

}

void UBullCowCartridge::SetupGame()
{
    //Welcomeing the Player
    PrintLine(TEXT("Happy July 16th 12:15!"));

    HiddenWord = TEXT("cakes"); 
    Lives = HiddenWord.Len(); 
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue..."));

    // const TCHAR HW[] = TEXT("plums");
    // PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
    // PrintLine(TEXT("The 4th character of HW is: %c"), HW[3]); 
    
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("\nPress enter to continue."));
}



    
    //Check if it's an isogram
    //Prompt to Guess Again

    //Check right answer of characters
    //Prompt to Guess Again

    //Remove Life
    
    //Check if lives > 0 
    //If Yes GuessAgain
    //Show Lives Left
    //If no GameOver and HiddenWord
    //Prompt to play again, Press Enter To Play Again? 
    //Check User Input    
    //PlayAgain or Quit

void UBullCowCartridge::ProcessGuess(FString Guess)
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
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

    //Check if lives > 0 
    //If Yes GuessAgain
    //Show Lives Left
    //If no GameOver and HiddenWord
    //Prompt to play again, Press Enter To Play Again? 
    //Check User Input    
    //PlayAgain or Quit

}

bool UBullCowCartridge::IsIsogram(FString Word) const
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

    // For reach letter,
    // Start at element [0],
    // Compare against the next letter, 
    // Until we reach [Word.Len() - 1],
    // if any are the same return false.  

    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(TArray<FString> WordList) const
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