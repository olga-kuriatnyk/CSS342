//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  Bank.h
//  Interface for Bank Class. Class reads transactions from the file ans stores them into an in-memory queue.
//  Also, process transactions in order and when processing done, it prints final balances.

#pragma once
#include <queue>
#include "BSTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class Bank
{
public:
    //  Constuctor
    Bank();

    //	Actions-verbs
    void ReadTransactionsFromTheFile();
    void ProcesTransactions();
    void Display() const;

    BSTree accounts_list; 

private:
    queue<Transaction> transactions_list;


    void printAccountIdError(Transaction front_trns, int account_id) const;
};

