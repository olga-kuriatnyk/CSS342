//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  Account.h
//  Interface for Account Class. Class stores all the information about each Account. 
//  Also, each account has 10 funds that are stored in an array.
//  Account clas sincludes functions for deposit and withdraw funds. 
//  Also, functions for printing history of an account and a fund.

#pragma once
#include "Transaction.h"
#include "Fund.h" 
#include <string>
#include <array>
using namespace std;

const int FUND_MAX = 10; // max size of the funds array

// for lineked funds
const int MONEY_MARKET = 0;
const int PRIME_MONEY_MARKET = 1;
const int LONG_TERM_BOND = 2;
const int SHORT_TERM_BOND = 3;

class Account
{
	//	Operator overload
	friend ostream& operator << (ostream& out, Account& account);

public:
	//  Constructor-Copy Constructor-Destuctor
	Account();
	Account(string first_name, string last_name, int account_id);
	~Account();

	//	Actions-verbs
	void depositAmount(int fund_id, int amount);
	bool withdrawAmount(int fund_id, int amount, Transaction trns); 
	void recordTransaction(Transaction trns, int fund_id);

	void printAccountHistory() const; 
	void printFundHistory(int fund_id) const; 

	//  Getter-Setters
	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getFundID() const;
	int getBalance(int fund_id)const;
	void setFundID(int fund_id);
	string getFundName(int fund_id) const;

private:
	string first_name_, last_name_;
	int account_id_, fund_id_;
	Fund funds[FUND_MAX];

	void withdrawFromSimilarAccoutns(int primary_fund, int secondary_fund, int amount);
	void faild_withdraw(int fund, int amount, Transaction trns);
};

