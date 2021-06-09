// MyCasino.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CardDeck.h"
#include "Card.h"

int main()
{
    Card cardA;
    Card cardB(5, Heart);
    Card cardC(67, Heart);

//    cardC.Print();
    cout << cardC << endl;
    cout << cardA << endl;
    cout << cardB << endl;

    
}

