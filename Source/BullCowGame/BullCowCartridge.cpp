// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hi Henry!"));
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic Number!
    PrintLine(TEXT("Input something and press enter"));
    HiddenWord = TEXT("cake");
    PlayerLives = 3;
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
        PrintLine(Input);
        PrintLine(TEXT("is not correct!"));
        --PlayerLives;
        if (PlayerLives == 0)
        {
            PrintLine(TEXT("Game Over"));
        }
    }
    

}