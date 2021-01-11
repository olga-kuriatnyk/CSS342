//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Bank.h" 
#include "BSTree.h"

int main()
{
	Bank jolly_bank;
	jolly_bank.ReadTransactionsFromTheFile(); // read
	jolly_bank.ProcesTransactions(); // execute 
	jolly_bank.Display(); // print

	//BSTree my_bst;
	//my_bst = jolly_bank.accounts_list;
	//cout << "BSTREE COPY" << endl;
	//my_bst.Display();
	//jolly_bank.Display();

	cout << "Empty trees " << endl;
	BSTree bst1;
	jolly_bank.accounts_list = bst1;
	bst1.Display();
	jolly_bank.accounts_list.Display();

}
