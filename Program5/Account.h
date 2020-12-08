#pragma once
#include "Transaction.h"
#include "Fund.h" 
#include <string>
#include <vector>
using namespace std;

const int MONEY_MARKET = 0;
const int PRIME_MONEY_MARKET = 1;
const int LONG_TERM_BOND = 2;
const int SHORT_TERM_BOND = 3;

class Account
{
public:
	Account();
	Account(string first_name, string last_name, int account_id);
	~Account();

	void depositAmount(int fund_id, int amount);
	bool withdrawAmount(int fund_id, int amount, Transaction trns); 
	void withdrawFromSimilarAccoutns(int primary_fund, int secondary_fund, int amount);
	//void withdrawFromSimilarAccountsFaild(int primary_fund, int amount);
	void faild_withdraw(int fund, int amount);
	void recordTransaction(Transaction trns, int fund_id);

	void printAccountHistory() const; // by fund
	void printFundHistory(int fund_id) const;

	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getFundID() const;
	int getBalance(int fund_id)const;
	void setFundID(int fund_id);

	string getFundName(int fund_id) const;

	// print history of account. from instructor notes: "Transaction History for FN LN by fund."

	// TODO: implement operators overload ><, so the BSTree can compare account_id to store them 

private:
	string first_name_, last_name_;
	int account_id_, fund_id_;
	vector<Fund> funds;

	void error(int amount, string first_name, string last_name, int fund_id);
};

