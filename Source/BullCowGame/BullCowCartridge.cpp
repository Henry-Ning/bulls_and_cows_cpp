// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    //Welcomeing the Player
    PrintLine(TEXT("Happy July 8th!"));
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic Number!
    PrintLine(TEXT("Input something and press enter"));
    
    SetupGame();

    //Prompt player to guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    if (Input == HiddenWord) 
    {
        PrintLine(TEXT("You win"));
    }
    else 
    {
        if (Input.Len() != HiddenWord.Len()) 
        {
            PrintLine(TEXT("The Hidden Word is 4 characters long, try again!"));
        }
        PrintLine(TEXT("You have lost!"));
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

}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cake"); 
    Lives = 4; 
}