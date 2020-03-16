#include <iostream>

int main()
{
    // Output story lines to Terminal

    std::cout << "You are a secret agent breaking into a secure server room";
    std::cout << std::endl;
    std::cout << "You need to enter the correct codes to contirnue...";
    std::cout << std::endl;

    // Declare 3 number code
    
    const int a = 4;
    const int b = 3;
    const int c = 2;

    const int sum = a + b + c;
    const int product = a * b * c;

    std::cout << sum << std::endl;;
     
    std::cout << product << std::endl;;
    
    return 0;
}
