// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); //Debug line

    //Welcomeing the Player
    PrintLine(TEXT("Happy July 8th!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter"));
    

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
            PrintLine(TEXT("The Hidden Word is %i characters long, try again!"), HiddenWord.Len());
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
    HiddenWord = TEXT("cakes"); 
    Lives = 4; 
}