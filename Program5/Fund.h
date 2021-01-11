//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  Fund.h 
//  Interface for Fund Class. Class stores the information each clients fund.  
//  Class stores the history of each fund in a vector (failed transactions included). 


#pragma once
#include "Transaction.h"
#include <string>
#include <vector>
#include <iostream>

class Fund
{
public:
    //  Constructor-Desctuctor
    Fund();
    ~Fund();

    //	Actions-verbs
    void depositAmountFund(int add_amount);
    bool withdrawAmountFund(int withdraw_amount);
    bool balanceCheck(int withdraw_amount);

    void recordFundTransaction(Transaction transaction);
    void printHistoryOfFund() const;
    void printHistory() const;

    //  Getter-Setters
    void setFundName(string fund_name);
    string getFundName() const;
    int getBalance() const;

private:
    string fund_name_ = "";
    int balance_ = 0;
    vector<Transaction> history; 

};

