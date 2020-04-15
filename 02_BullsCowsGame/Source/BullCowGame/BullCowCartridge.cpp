// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
//#include "Math/UnrealMathUtility.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(Words);

    SetupGame(); // Setting up game
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // checking player guess
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::ProcessGuess(const FString &Guess)
{
    if (Guess == HiddenWord) // Guess cheking
    {
        PrintLine(TEXT("YOU WON!!!"));
        EndGame();
        return;
    }

    if (HiddenWord.Len() != Guess.Len()) // checking length of wordss
    {
        PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    if (Lives <= 1)
    {
        PrintLine(TEXT("You have no lives left"));
        EndGame();
        return;
    }

    PrintLine(TEXT("TRY AGAIN!!!"));

    FBullCowCount Score = GetBullsCows(Guess);
    PrintLine(TEXT("You Have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);

    --Lives;
    PrintLine(TEXT("You have %i lives left!"), Lives);
}

void UBullCowCartridge::SetupGame()
{
    //Welcome player
    PrintLine(TEXT("Welcome do Bull Cows Game!"));

    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)]; // guess word -1 cause we start from 0
    Lives = HiddenWord.Len();                                       // setting num. oflives
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives left!"), Lives);
    PrintLine(TEXT("Write word and press enter!"));
    //PrintLine(TEXT("Hidden word is: %s"), *HiddenWord); // debug line
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again..."));
}

bool UBullCowCartridge::IsIsogram(const FString &Word) const // const because doesnt change any member variable
{
    for (int32 i = 0; i < Word.Len(); i++)
    {
        for (int32 j = i + 1; j < Word.Len(); j++)
        {
            if (Word[i] == Word[j])
            {
                return false;
            }
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString> &WordList) const
{
    TArray<FString> ValidWords;

    for (FString WordFromWordList : WordList) // RANGE-BASED LOOP if 4=< word.len <=8
    {
        if (WordFromWordList.Len() >= 4 && WordFromWordList.Len() <= 8 && IsIsogram(WordFromWordList))
        {
            ValidWords.Emplace(WordFromWordList);
        }
    }

    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullsCows(const FString &Guess) const
{
    FBullCowCount Count;
    for (int32 i = 0; i < Guess.Len(); i++)
    {
        if (Guess[i] == HiddenWord[i])
        {
            Count.Bulls++;
            continue;
        }

        for (int32 j = 0; j < HiddenWord.Len(); j++)
        {
            if (Guess[i] == HiddenWord[j])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}