#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaction
{
	friend ostream& operator<<(ostream& out, const Transaction& trns); // TODO: implement for transwer and history 

public:
	Transaction();
	Transaction(char trns_type, string last_name, string first_name, int account_id);  //for Open transactions
	Transaction(char trns_type, int fund_id, int amoun);  //for Deposit and Withdraw
	Transaction(char trns_type, int account_id, int fund_id, int amount, int transfer_account_id, int transfer_fund_id); //for Transfer
	Transaction(char trns_type, int account_id);  //for History
	//Transaction(char transaction_type, int fund_id);  //for History
	~Transaction(); 

	// I DONT KNOW IF THIS WORKS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	char getTransactionType() const;
	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getFundID() const;
	int getTransferAccountID() const;
	int getTransferFundID() const;
	int getAmount() const;

	// bool isFailed(); // executed_copectly_function 

private:
	string first_name_, last_name_;
	char trns_type_;
	int account_id_, fund_id_, amount_, transfer_account_id_, transfer_fund_id_;
};

