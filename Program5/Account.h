#pragma once
#include "Transaction.h"
#include "Fund.h" 
#include <string>
#include <vector>
using namespace std;

class Account
{
public:
	Account();
	Account(string first_name, string last_name, int account_id);
	~Account();

	void depositAmount(int fund_id, int amount);
	bool withdrawAmount(int fund_id, int amount);
	void recordTransaction(Transaction trans, int fund_id);
	void printAccountHistory() const; // by fund
	void printFundHistory(int fund_id) const;

	int getAccountID() const;
	int getFundID() const;
//	int getBalance(int fund_id)const;
	string getFundName(int fund_id) const;
	string getFirstName() const;
	string getLastName() const;
	void setFundID(int fund_id);

	// print history of account. from instructor notes: "Transaction History for FN LN by fund."

	// TODO: implement operators overload ><, so the BSTree can compare account_id to store them 

private:
	string first_name_, last_name_;
	int account_id_, fund_id_;
	vector<Fund> funds;

};

