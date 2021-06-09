//  Olga Kuraitnyk
//  CSS342A
//  11/02/2020
//  Problem 1: The good Mr. Catalan.

// This file contains the 'main' function. Program execution begins and ends there.
// And this file contains a recursive function compute Catalan which takes one argument. 

#include <iostream>

int computeCatalan(int num);

int main(int argc, char* argv[])
{
    int num; 
    std::cout << "Enter number to calculate Catalan number: ";
    std::cin >> num ;
    if (num < 0)
    {
        std::cout << "Cannot count Catalan number for negative input " << std::endl;
    }
    else
    {
        std::cout << "Catalan number of " << num << ": " << computeCatalan(num) << std::endl;
    }
}

int computeCatalan(int num) 
{
    int sum = 0;
    if (num == 0)
    {
       sum = 1;
    }
    else if (num > 0)
    {
        
        for (int i = 0; i < num; i++)
        {
            sum += computeCatalan(i) * computeCatalan(num - i - 1);
        }       
    }
    return sum;
}