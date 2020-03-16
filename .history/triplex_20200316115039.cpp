#include <iostream>

int main()
{
    // Output story lines to Terminal

    std::cout << "You are a secret agent breaking into a secure server room";
    std::cout << std::endl;
    std::cout << "You need to enter the correct codes to continue...";
    std::cout << std::endl;

    // Declare 3 number code

    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to Terminal

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to " << CodeSum << std::endl;
     
    std::cout << "+ The codes multiply to give " << CodeProduct << std::endl;;
    
    // Store Player Guess

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB ;
    

    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win!!!";
    }
    else
    {
        std::cout << "You Lose!!!";
    }
    
    return 0;
}
