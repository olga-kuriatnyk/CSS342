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
    char chr2 = 'D';
    char chr3 = 'T';
    char chr4 = 'W';

    string ln = "Kur";
    string fn = "Olga";
    int account = 1234;
    int fund = 1;
    int amount = 1000;

    Transaction trans(chr, ln, fn, account);
    cout << trans << endl;
    Transaction trans2(chr2, account, fund, amount);
    cout << trans2 << endl;

    int transfer_account_id = 4321;
    int transfer_fund_id = 9;
    string fail = "fail";


    Transaction trans3(chr3, account, fund, amount, transfer_account_id, transfer_fund_id, fail);
    cout << trans3 << endl;
    Transaction trans4(chr4, account, fund, amount, fail);
    cout << trans4 << endl;


    std::cout << "Hello World!\n";
}