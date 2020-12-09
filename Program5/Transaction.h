#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaction
{
	friend ostream& operator<<(ostream& out, const Transaction& trns); // TODO: implement for transwer and history 

public:
	Transaction();
	~Transaction();
	Transaction(char trns_type, string last_name, string first_name, int account_id);  //for Open transactions
	Transaction(char trns_type, int account_id, int fund_id, int amount);  //for Deposit and Withdraw
	Transaction(char trns_type, int account_id, int fund_id, int amount, int transfer_account_id, int transfer_fund_id); //for Transfer
	Transaction(char trns_type, int account_id);  //for account History
//	Transaction(char trns_type, int account_id, int fund_id);  //for fund History

	//These Construtors create a transaction that failed to process
	Transaction(char trns_type, int account_id, int fund_id, int amount, int transfer_account_id, int transfer_fund_id, string fail);
	Transaction(char trns_type, int account_id, int fund_id, int amount, string fail);

	char getTransactionType() const;
	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getFundID() const;
	int getTransferAccountID() const;
	int getTransferFundID() const;
	int getAmount() const;
	bool isFailed() const; 

private:
	string first_name_ = "", last_name_ = "", fail_ = "";
	char trns_type_;
	int account_id_ = 0, fund_id_ = 0, amount_ = 0, transfer_account_id_ = 0, transfer_fund_id_ = 0;
};

