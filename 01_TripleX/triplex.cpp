#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty, int CodeSum, int CodeProduct)
{
    cout << "\nYou are server agent breaking into a level " << Difficulty;
    cout << " secure server room...\nEnter the correct code to continue...\n";
    cout << "There are 3 numbers in the code\n";
    cout << "The codes add-up to: " << CodeSum << "\n";
    cout << "The codes multiply to give: " << CodeProduct << "\n";
}

int InputGuess(int Guess[])
{
    //int Guess[3];
    for (int i = 0; i < 3; i++)
    { // input loop
        cout << "Enter Code " << i + 1 << ": ";
        cin >> Guess[i];
        cout << "You entered: " << Guess[i] << "\n";
    }
    return *Guess;
}

bool HakerCheck(bool GameState) // finish it one day...
{
    return 0;
}

int RandomCode(int Difficulty)
{
    int Random = rand() % Difficulty + Difficulty;
    return Random;
}

int GenegarePassword(int Guess[]) /// finish it one day  
{
    int GuessSum = 0;
    int GuessProduct = 1;
    return GuessSum, GuessProduct;
}
bool PlayGame(int Difficulty)
{
    // declaring codes and sequence
    const int CodeA = RandomCode(Difficulty); // const means you will never change it
    const int CodeB = RandomCode(Difficulty);
    const int CodeC = RandomCode(Difficulty);

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    int Guess[3]; // array of inout for 3 codes

    PrintIntroduction(Difficulty, CodeSum, CodeProduct);
    InputGuess(Guess);
    //TestGuessInput(Guess); //finish test function later...

    int GuessSum = 0;
    int GuessProduct = 1;

    for (int i = 0; i < sizeof Guess / sizeof Guess[0]; i++) // calculating sum and product
    {
        GuessSum += Guess[i];
        GuessProduct = GuessProduct * Guess[i];
    }

    //cout << GuessSum << " " << GuessProduct; //calculation test

    //HakerCheck();
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "Nice one haker keep going\n";
        return true;
    }
    else
    {
        cout << "You lose you try again\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // random based on time

    int LevelDifficulty = 1;
    int const MaxLevelDiffculty = 3;

    while (LevelDifficulty <= MaxLevelDiffculty) // lopp game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();  // clear any errors
        cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    cout << "You are fckin rich now";

    return 0;
}