// TheJollyBanker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bank.h" 

int main()
{
	Bank jolly_bank;
	jolly_bank.ReadTransactionsFromTheFile();
	jolly_bank.ProcesTransactions(); // execute transactions
	jolly_bank.Display();


	std::cout << "Hello World!\n";
}
