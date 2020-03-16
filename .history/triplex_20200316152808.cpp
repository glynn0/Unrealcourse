#include <iostream>

void PrintIntroduction(int Difficulty)
{
    // Output story lines to Terminal
    std::cout << "---------------------------------------------------------\n";
    std::cout << "You are a secret agent breaking into a Level " << Difficulty;
    std::cout << " secure server room\nYou need to enter the correct codes to continue...\n";
    std::cout << "---------------------------------------------------------\n";
}

bool PlayGame(int Difficulty)
{
    
   PrintIntroduction(Difficulty);

    // Declare 3 number code

    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to Terminal

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code\n" ;
    std::cout << "+ The codes add up to " << CodeSum << "\n";
     
    std::cout << "+ The codes multiply to give " << CodeProduct << "\n\n";
    
    // Store Player Guess

    int GuessA, GuessB, GuessC;
    std::cout << "Please Enter your Code --> ";
    std::cin >> GuessA >> GuessB >> GuessC;
    

    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    // Check to see if the players guess is correct

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win!!!\n";
        return(true);
    }
    else
    {
        std::cout << "You Lose!!!\n";
        return(false);
    }
    
}

int main()
{
    int LevelDifficulty = 1;

    while (true)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    return 0;
}
