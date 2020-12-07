// TheJollyBanker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bank.h" 

int main()
{
   // Bank jolly_bank; 
   //jolly_bank.ProcesTransactions(); // execute transactions
   //cout << jolly_bank << endl; // print the final balanses 


    char chr = 'O';
    string ln = "Kur";
    string fn = "Olga";
    int account = 1234;

    Transaction trans(chr, ln, fn, account);

    cout << trans << endl;
    



    std::cout << "Hello World!\n";
}
