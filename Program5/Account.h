#pragma once
#include "Transaction.h"
#include "Fund.h" 
#include <string>
//#include <vector>
#include <array>
using namespace std;

const int FUND_MAX = 10;

const int MONEY_MARKET = 0;
const int PRIME_MONEY_MARKET = 1;
const int LONG_TERM_BOND = 2;
const int SHORT_TERM_BOND = 3;

class Account
{
	friend ostream& operator << (ostream& out, Account& account);

public:
	Account();
	Account(string first_name, string last_name, int account_id);
	~Account();

	void depositAmount(int fund_id, int amount);
	bool withdrawAmount(int fund_id, int amount, Transaction trns); 
	void recordTransaction(Transaction trns, int fund_id);

	void printAccountHistory() const; 
	void printFundHistory(int fund_id) const; 

	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getFundID() const;
	int getBalance(int fund_id)const;
	void setFundID(int fund_id);

	string getFundName(int fund_id) const;

	bool operator>(const Account& account) const; // TODO: so the BSTree can compare account_id to store them 
	bool operator<(const Account& account) const;


private:
	string first_name_, last_name_;
	int account_id_, fund_id_;
	Fund funds[FUND_MAX];

	void withdrawFromSimilarAccoutns(int primary_fund, int secondary_fund, int amount);
	void faild_withdraw(int fund, int amount);
};

