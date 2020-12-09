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

void Fund::depositAmountFund(int add_amount)
{
	balance_ += add_amount;
}

bool Fund::withdrawAmountFund(int withdraw_amount)
{
	if (balanceCheck(withdraw_amount))
	{
		balance_ -= withdraw_amount;
		return true;
	}
	// cout << "ERROR: Not enough funds to withdraw " << withdraw_amount << " from " << this->getFirstName() << this->getLastName << fund_name << endl;
	return false;
}

void Fund::recordFundTransaction(Transaction transaction)
{
	history.push_back(transaction);
}

void Fund::printHistoryOfFund() const
{
	for (int i = 0; i < history.size(); i++)
	{
		cout << "  " << history[i];
	}
}

void Fund::printHistory() const
{
	if (history.size() == 0)
	{
		return;
	}
	else
	{
		cout << fund_name_ << ": $" << balance_ << endl;
		for (int i = 0; i < history.size(); i++)
		{
			cout << "  " << history[i];
		}
	}
}

void Fund::setFundName(string fund_name)
{
	this->fund_name_ = fund_name;
}

string Fund::getFundName() const
{
	return fund_name_;
}

bool Fund::balanceCheck(int withdraw_amount)
{
	if (balance_ >= withdraw_amount)
	{
		return true;
	}
	return false;
}