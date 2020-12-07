#include "Transaction.h"

Transaction::Transaction()
{
}
Transaction::~Transaction()
{
}

Transaction::Transaction(char trns_type, string last_name, string first_name, int account_id)
{
	this->trns_type_ = trns_type;
	this->last_name_ = last_name;
	this->first_name_ = first_name;
	this->account_id_ = account_id;
}

Transaction::Transaction(char trns_type, int fund_id, int amoun)
{
	this->trns_type_ = trns_type;
	this->fund_id_ = fund_id;
	this->amount_ = amoun;
}
Transaction::Transaction(char trns_type, int account_id, int fund_id, int amount, int transfer_account_id, int transfer_fund_id)
{
	this->trns_type_ = trns_type;
	this->account_id_ = account_id;
	this->fund_id_ = fund_id;
	this->amount_ = amount;
	this->transfer_account_id_ = transfer_account_id;
	this->transfer_fund_id_ = transfer_fund_id;
}

Transaction::Transaction(char trns_type, int account_id)
{
	this->trns_type_ = trns_type;
	this->account_id_ = account_id;
}

char Transaction::getTransactionType() const
{
	return trns_type_;
}

string Transaction::getFirstName() const
{
	return first_name_;
}

string Transaction::getLastName() const
{
	return last_name_; 
}

int Transaction::getAccountID() const
{
	return account_id_;
}

int Transaction::getFundID() const
{
	return fund_id_;
}

int Transaction::getTransferAccountID() const
{
	return transfer_account_id_;
}

int Transaction::getTransferFundID() const
{
	return transfer_fund_id_;
}

int Transaction::getAmount() const
{
	return amount_;
}

ostream& operator<<(ostream& out, const Transaction& trns)
{
	if ((trns.getTransactionType() == 'D') || (trns.getTransactionType() == 'W'))
	{
		cout << trns.getTransactionType() << " " << trns.getAccountID() << trns.getFundID() << " " << trns.getAmount() << endl;
	}
	else if (trns.getTransactionType() == 'O')
	{
		cout << trns.getTransactionType() << " " << trns.getLastName() << " " << trns.getFirstName() << " " << trns.getAccountID() << endl;
	}
	else if (trns.getTransactionType() == 'T')
	{
		cout << trns.getTransactionType() << " " << trns.getAccountID() << trns.getFundID << " " << trns.getAmount() << " " << trns.getTransferAccountID << trns.getTransferFundID << endl;
	}
	else if (trns.getTransactionType() == 'H') {} // TODO: question: do we need to store the History transaction in our history? 

	return out;
}