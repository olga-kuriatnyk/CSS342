//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  Transaction.h
//  Interface for Transaction Class. Class stors all the information about each transaction.

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaction
{
	//	Operator overload
	friend ostream& operator<<(ostream& out, const Transaction& trns); 

public:
	//  Constructor-Desctuctor
	Transaction();
	~Transaction();

	//Copy Constructors 
	Transaction(char trns_type, string last_name, string first_name, int account_id);  //for Open transactions
	Transaction(char trns_type, int account_id, int fund_id, int amount);  //for Deposit and Withdraw
	Transaction(char trns_type, int account_id, int fund_id, int amount, int transfer_account_id, int transfer_fund_id); //for Transfer
	Transaction(char trns_type, int account_id);  //for account History

	//These Copy Construtors create a transaction that failed to process
	Transaction(char trns_type, int account_id, int fund_id, int amount, int transfer_account_id, int transfer_fund_id, string fail);
	Transaction(char trns_type, int account_id, int fund_id, int amount, string fail);

	//  Getter-Setters
	char getTransactionType() const;
	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getFundID() const;
	int getTransferAccountID() const;
	int getTransferFundID() const;
	int getAmount() const;
	string getFailed() const;
	bool isFailed() const; 

private:
	string first_name_ = "", last_name_ = "", fail_ = "";
	char trns_type_;
	int account_id_ = 0, fund_id_ = 0, amount_ = 0, transfer_account_id_ = 0, transfer_fund_id_ = 0;
};

