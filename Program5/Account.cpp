//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  Account.cpp
//  The implementation for Account Class. 

#include "Account.h"

Account::Account()
{
	first_name_ = "";
	last_name_ = "";
	account_id_ = 0;
	fund_id_ = 0;
}

//The constructor creates an account with a first and last anme, account ID
//and gives names to the corresponding funds 
Account::Account(string first_name, string last_name, int account_id)
{
	this->first_name_ = first_name;
	this->last_name_ = last_name;
	this->account_id_ = account_id;
	string fundNames[] = { "Money Market", "Prime Money Market","Long-Term Bond", "Short-Term Bond",
		"500 Index Fund", "Capital Value Fund","Growth Equity Fund", "Growth Index Fund","Value Fund",
		"Value Stock Index" };
	for (int i = 0; i < 10; i < i++)
	{
		funds[i].setFundName(fundNames[i]);
	}
}

Account::~Account()
{
}

// call the Fund clas function depositAmountFund() for specified fund
void Account::depositAmount(int fund_id, int amount)
{
		funds[fund_id].depositAmountFund(amount);
}

// The withdrawAmoun()t function is used for withdraw of money.
// First it checks if the fund_id is any of the special funds (index 0-3).
// If they are not, they proceed to trying to subtract from the balance available. 
// If they are part of the speical linked index the fucnction first checks if it can widthdrwal from the primary fund index.
// If it cannot, it then checks if the amount subtracted is less than the total of the combined of two funds.
// If it cannot widthdrawl from 2 funds it shoots out and error, and transactions is added to history as failed 
bool Account::withdrawAmount(int fund_id, int amount, Transaction trns)
{
	if (fund_id == MONEY_MARKET || fund_id == PRIME_MONEY_MARKET)
	{
		if (funds[fund_id].balanceCheck(amount))
		{
			funds[fund_id].withdrawAmountFund(amount);
			funds[fund_id].recordFundTransaction(trns);
			return true;
		}

		else if ((funds[MONEY_MARKET].getBalance() + funds[PRIME_MONEY_MARKET].getBalance()) >= amount)
		{

			if ((fund_id == MONEY_MARKET) && (trns.getTransferFundID() != PRIME_MONEY_MARKET))
			{
				withdrawFromSimilarAccoutns(MONEY_MARKET, PRIME_MONEY_MARKET, amount);
				return true;
			}
			else if ((fund_id == PRIME_MONEY_MARKET) && (trns.getTransferFundID() != MONEY_MARKET))
			{
				withdrawFromSimilarAccoutns(PRIME_MONEY_MARKET, MONEY_MARKET, amount);
				return true;
			}

		}

		else if ((!funds[fund_id].balanceCheck(amount)) && ((trns.getTransferFundID() == PRIME_MONEY_MARKET) || (trns.getTransferFundID() == MONEY_MARKET)))
		{
			faild_withdraw(fund_id, amount, trns);
			return false;
		}

		else // two funds together have not enough money to withdraw
		{
			if (fund_id == MONEY_MARKET)
			{
				faild_withdraw(MONEY_MARKET, amount, trns);
				return false;
			}
			else
			{
				faild_withdraw(PRIME_MONEY_MARKET, amount, trns);
				return false;
			}
		}
	}

	else if (fund_id == LONG_TERM_BOND || fund_id == SHORT_TERM_BOND)
	{
		if (funds[fund_id].balanceCheck(amount))
		{
			funds[fund_id].withdrawAmountFund(amount);
			funds[fund_id].recordFundTransaction(trns);
			return true;
		}

		else if ((!funds[fund_id].balanceCheck(amount)) && ((trns.getTransferFundID() == LONG_TERM_BOND) || (trns.getTransferFundID() == SHORT_TERM_BOND)))
		{
			faild_withdraw(fund_id, amount, trns);
			return false;
		}

		else if ((funds[LONG_TERM_BOND].getBalance() + funds[SHORT_TERM_BOND].getBalance()) >= amount)
		{
			if (fund_id == LONG_TERM_BOND)
			{
				withdrawFromSimilarAccoutns(LONG_TERM_BOND, SHORT_TERM_BOND, amount);
				return true;
			}
			else
			{
				withdrawFromSimilarAccoutns(SHORT_TERM_BOND, LONG_TERM_BOND, amount);
				return true;
			}
		}
		else // two funds together have not enough money to withdraw
		{
			if (fund_id == LONG_TERM_BOND)
			{
				faild_withdraw(LONG_TERM_BOND, amount, trns);

				return false;
			}
			else
			{
				faild_withdraw(SHORT_TERM_BOND, amount, trns);

				return false;
			}
		}
	}
	else
	{
		if (funds[fund_id].balanceCheck(amount))
		{
			funds[fund_id].withdrawAmountFund(amount);
			funds[fund_id].recordFundTransaction(trns);
			return true;
		}
		else
		{
			//faild_withdraw(fund_id, amount);
			faild_withdraw(fund_id, amount, trns);
			return false;
		}
	}

	return false;
}

// withdrawFromSimilarAccoutn() function is used for the withdrawl if two linked accounts 
void Account::withdrawFromSimilarAccoutns(int primary_fund, int secondary_fund, int amount) 
{
	int available_balance = funds[primary_fund].getBalance();
	funds[primary_fund].withdrawAmountFund(available_balance);
	Transaction trns('W', getAccountID(), primary_fund, available_balance);
	funds[primary_fund].recordFundTransaction(trns);

	amount = amount - available_balance;

	funds[secondary_fund].withdrawAmountFund(amount);
	Transaction trns2('W', getAccountID(), secondary_fund, amount);
	funds[secondary_fund].recordFundTransaction(trns2);
}

// function that prints the right Error message and add failed transaction to the record
void Account::faild_withdraw(int fund, int amount, Transaction trns)
{ 
	if (trns.getTransactionType() == 'T')
	{
		cerr << "ERROR: Not Enought Funds to Transer " << amount << " from " << getAccountID() << fund << " to " << trns.getTransferAccountID() << trns.getTransferFundID() << endl;
		
		Transaction trns('T', getAccountID(), fund, amount, trns.getTransferAccountID(), trns.getTransferFundID(), "(Failed)");
		
		funds[fund].recordFundTransaction(trns);
		funds[trns.getTransferFundID()].recordFundTransaction(trns);
	}
	else if (trns.getTransactionType() == 'W')
	{
		cerr << "ERROR: Not Enough Funds to withdraw " << amount << " from " << getFirstName() << " " << getLastName() << " " << getFundName(fund) << endl;
		
		Transaction trns('W', getAccountID(), fund, amount, "(Failed)"); // failed transactoin for the record
		
		funds[fund].recordFundTransaction(trns);
	}
}


void Account::recordTransaction(Transaction trns, int fund_id)
{
	funds[fund_id].recordFundTransaction(trns);
}

// Print History for All Funds in the Account 
void Account::printAccountHistory() const
{
	cout << "Transaction History for " << first_name_ << " " << last_name_ << " by fund." << endl;
	for (int i = 0; i < FUND_MAX; i++)
	{
		funds[i].printHistory();
	}
}

// Print History of a single Fund
void Account::printFundHistory(int fund_id) const
{
	cout << "Transaction History for " << first_name_ << " " << last_name_ << " " << getFundName(fund_id) << ": $" << getBalance(fund_id) << endl;
	funds[fund_id].printHistoryOfFund();
}

int Account::getAccountID() const
{
	return account_id_;
}

int Account::getFundID() const
{
	return fund_id_;
}

int Account::getBalance(int fund_id) const
{
	return funds[fund_id].getBalance();
}

string Account::getFirstName() const
{
	return first_name_;
}

string Account::getLastName() const
{
	return last_name_;
}

void Account::setFundID(int fund_id)
{
	this->fund_id_ = fund_id;
}

string Account::getFundName(int fund_id) const
{
	return funds[fund_id].getFundName();
}

ostream& operator<<(ostream& out, Account& account)
{
	out << account.getFirstName() << " " << account.getLastName() << " Account ID: " << account.getAccountID() << endl;
	for (int i = 0; i < 10; i++)
	{
		out << "    " << account.getFundName(i) << ": $" << account.getBalance(i) << endl;
	}
	return out;
}
