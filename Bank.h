#pragma once
#include <queue>
#include "BSTree.h"
#include "Transaction.h"
#include "BSTree.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class Bank
{
public:
    Bank();
    bool ReadTransactionsFromTheFile();
    void ProcesTransactions(); 

    //operator overload << //Display 

private:
    queue<Transaction> transactions_list_;
    BSTree accounts_list_;
};

