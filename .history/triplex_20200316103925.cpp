#include <iostream>

int main()
{
    // Output story lines to Terminal

    std::cout << "You are a secret agent breaking into a secure server room";
    std::cout << std::endl;
    std::cout << "You need to enter the correct codes to contirnue...";
    std::cout << std::endl;

    // Declare 3 number code

    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;



    const int Codesum = CodeA + CodeB + CodeC;
    const int product = CodeA * CodeB * CodeC;

    // Print Sum and Product to Terminal

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to " << sum << std::endl;
     
    std::cout << "+ The codes multiply to give " << product << std::endl;;
    
    return 0;
}
