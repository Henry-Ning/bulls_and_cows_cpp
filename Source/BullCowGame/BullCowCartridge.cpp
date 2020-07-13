// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    SetupGame();

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
    PrintLine(TEXT("Happy July 13th!"));

    HiddenWord = TEXT("cakes"); 
    Lives = HiddenWord.Len(); 
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue..."));
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
    
    //Check if it's an isogram
    //Prompt to Guess Again

    // if(!IsIsogram)
    // {
    //     PrintLine(TEXT("No repeating letters, guess again"));
    // }

    if (Guess.Len() != HiddenWord.Len()) 
    {
        PrintLine(TEXT("The Hidden Word is %i letters long!"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
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