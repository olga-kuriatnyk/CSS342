#pragma once
#include <queue>
#include "BSTree.h"
//#include "Transaction.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class Bank
{
    //friend ostream& operator<<(ostream& out, const Bank& bank); 

public:
    Bank();
    void ReadTransactionsFromTheFile();
    void ProcesTransactions(); 

    //operator overload << //Display 

private:
    queue<Transaction> transactions_list;
    BSTree accounts_list;
};

