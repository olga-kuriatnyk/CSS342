#include "Account.h"

Account::Account()
{
}

Account::Account(string first_name, string last_name, int account_id)
{
	this->first_name_ = first_name;
	this->last_name_ = last_name;
	this->account_id_ = account_id;
	string fundNames[] = { "Money Market", "Prime Money Market","Long-Term Bond", "Short-Term Bond","500 Index Fund", "Capital Value Fund","Growth Equity Fund", "Growth Index Fund","Value Fund", "Value Stock Index" };
	for (int i = 0; i < 10; i < i++)
	{
		funds[i].setFundName(fundNames[i]);
	}
}

Account::~Account()
{
}

int Account::getAccountID() const
{
	return account_id_;
}
