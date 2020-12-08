#pragma once
#include "Transaction.h"
#include <string>
#include <vector>
#include <iostream>
//using namespace std;


class Fund
{
public:
    Fund();
    ~Fund();

    void depositAmountFund(int add_amount);
    bool withdrawAmountFund(int withdraw_amount);
    bool balanceCheck(int withdraw_amount);

    void recordFundTransaction(Transaction transaction);
    void printHistoryOfFund();

    void setFundName(string fund_name);
    string getFundName() const;
    int getBalance() const;

private:
    string fund_name_ = "";
    int balance_ = 0;
    vector<Transaction> history; //store faild transactions in history of a fund 

};

