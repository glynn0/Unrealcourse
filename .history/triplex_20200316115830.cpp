#include <iostream>


void PlayGame()
{
// Output story lines to Terminal

    std::cout << "You are a secret agent breaking into a secure server room\n";
    
    std::cout << "You need to enter the correct codes to continue...\n";
   

    // Declare 3 number code

    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to Terminal

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code\n" ;
    std::cout << "+ The codes add up to \n" << CodeSum ;
     
    std::cout << "+ The codes multiply to give \n" << CodeProduct << "\n";
    
    // Store Player Guess

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;
    

    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    // Check to see if the players guess is correct

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win!!!\n";
    }
    else
    {
        std::cout << "You Lose!!!\n";
    }
    
}

int main()
{
    
    return 0;
}
