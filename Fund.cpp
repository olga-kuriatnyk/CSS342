#include "Fund.h"

Fund::Fund()
{
	balance_ = 0;
}

Fund::~Fund()
{
}

int Fund::getBalance() const
{
	return balance_;
}

void Fund::depositAmount(int add_amount)
{
	balance_ += add_amount;
}

bool Fund::withdrawAmount(int withdraw_amount)
{
	if (balanceCheck(withdraw_amount))
	{
		balance_ -= withdraw_amount;
		return true;
	}
	// cout << "ERROR: Not enough funds to withdraw " << withdraw_amount << " from " << this->getFirstName() << this->getLastName << fund_name << endl;
	return false;
}

void Fund::recordTransaction(Transaction transaction)
{
	history.push_back(transaction);
}

void Fund::printHistoryOfFund()
{
	for (int i = 0; i < history.size(); i++)
	{
		cout << history[i] << endl;
		//cout << " " << history[i]; 
	}
}

void Fund::setFundName(string fund_name)
{
	this->fund_name_ = fund_name;
}

bool Fund::balanceCheck(int withdraw_amount)
{
	if (balance_ >= withdraw_amount)
	{
		return true;
	}
	return false;
}