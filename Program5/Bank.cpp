//  Olga Kuraitnyk
//  CSS342A
//  12/10/2020
//  Program 5: The Jolly Banker
//  Bank.cpp
//  The implementation for Bank Class. 

#include "Bank.h"

Bank::Bank()
{
}

//The ReadTransactionsFromTheFile() fucntion, reads the input file and creates the 
//appropriate transaction and places them into the queue.
void Bank::ReadTransactionsFromTheFile()
{
	ifstream in("BankTransIn.txt");
	string readLine;

	if (!in)
	{
		cout << "CANNOT OPEN THE FILE" << endl;
	}

	while (!in.eof())
	{
		getline(in, readLine);
		if (readLine.empty())
		{
			break;
		}

		istringstream parseLine(readLine);
		char trns_type;
		int account_id, fund_id, amount, transfer_account_id, transfer_fund_id;

		parseLine >> trns_type;

		if (trns_type == 'O') // Create object Transaction with type 'O' and add to queue
		{
			string last_name, first_name;
			parseLine >> last_name >> first_name >> account_id;
			Transaction add_to_queue(trns_type, last_name, first_name, account_id);
			transactions_list.push(add_to_queue);
		}

		else if (trns_type == 'D' || trns_type == 'W') // Create object Transaction with type 'D' or 'W' and add to queue
		{
			parseLine >> account_id >> amount;
			fund_id = account_id % 10;
			account_id = account_id / 10;
			Transaction add_to_queue(trns_type, account_id, fund_id, amount);
			transactions_list.push(add_to_queue);
		}
		 
		else if (trns_type == 'T') // Create object Transaction with type 'T' and add to queue
		{
			parseLine >> account_id >> amount >> transfer_account_id;
			fund_id = account_id % 10;
			account_id = account_id / 10;
			transfer_fund_id = transfer_account_id % 10;
			transfer_account_id = transfer_account_id / 10;
			Transaction add_to_queue(trns_type, account_id, fund_id, amount, transfer_account_id, transfer_fund_id);
			transactions_list.push(add_to_queue);
		}

		else if (trns_type == 'H') // Create object Transaction with type 'H' and add to queue
		{
			parseLine >> account_id;
			Transaction add_to_queue(trns_type, account_id);
			transactions_list.push(add_to_queue);
		}

		else
		{
			cerr << "UNKNOWN TRANSACTION TYPE" << endl;
		}
	}
}

// Proces Transactions by its type. Prints Error messages if input data is not valid.
void Bank::ProcesTransactions()
{
	while (!transactions_list.empty())
	{
		Transaction front_trns = transactions_list.front();
		int account_id = front_trns.getAccountID();
		int amount = front_trns.getAmount();
		int fund_id = front_trns.getFundID();
		char trns_type = front_trns.getTransactionType();

		Account* account = NULL;

		if (trns_type == 'O') // process Open transactions
		{
			if (account_id >= 1000 || account_id <= 9999)
			{
				Account* account = new Account(front_trns.getFirstName(), front_trns.getLastName(), account_id);
				accounts_list.Insert(account);
			}

			else if (account_id < 1000 || account_id > 9999)
			{
				cerr << "ERROR: Account Number " << account_id << " Not Valid" << endl;
			}
		}

		else if (trns_type == 'D') // process Deposit transactions
		{
			if ((account_id >= 1000) && (account_id <= 9999))
			{

				if (accounts_list.Retrieve(account_id, account) && (amount > 0))
				{
					account->depositAmount(fund_id, amount);
					account->recordTransaction(front_trns, fund_id);
				}

				else if (!accounts_list.Retrieve(account_id, account))
				{
					printAccountIdError(front_trns, account_id);
				}

				else if (amount <= 0) // invalid amount input
				{
					Transaction  trns('D', account_id, fund_id, amount, "(Failed)");
					account->recordTransaction(trns, fund_id);
				}
			}

			else 
			{
				cerr << "ERROR: Account " << account_id << " not valid. Transaction " << front_trns << " refused." << endl;
			}
		}
		 
		else if (trns_type == 'W') // process Withdraw transactions
		{
			if ((account_id >= 1000) && (account_id <= 9999))
			{
				if (accounts_list.Retrieve(account_id, account) && (amount > 0))
				{
					account->withdrawAmount(fund_id, amount, front_trns);
				}

				else if (!accounts_list.Retrieve(account_id, account))
				{
					printAccountIdError(front_trns, account_id);
				}

				else if (amount <= 0) // invalid amount input
				{
					Transaction  trns('W', account_id, fund_id, amount, "(Failed)");
					account->recordTransaction(trns, fund_id);
				}
			}

			else
			{
				cerr << "ERROR: Account " << account_id << " not valid. Transaction " << front_trns << " refused." << endl;
			}
		}

		else if (trns_type == 'T') // process Transfer transactions
		{
			int transfer_account_id = front_trns.getTransferAccountID();
			int transfer_fund_id = front_trns.getTransferFundID();

			Account* to, * from;

			if (accounts_list.Retrieve(account_id, to) && accounts_list.Retrieve(transfer_account_id, from))
			{
				if (to->withdrawAmount(fund_id, amount, front_trns))
				{
					from->depositAmount(transfer_fund_id, amount);
					from->recordTransaction(front_trns, transfer_fund_id);
				}
			}

			else if (!accounts_list.Retrieve(account_id, account))
			{
				printAccountIdError(front_trns, account_id);
			}

			else if (!accounts_list.Retrieve(transfer_account_id, to))
			{
				printAccountIdError(front_trns, transfer_account_id);
			}
		}

		else if (trns_type == 'H') // process History transactions 
		{
			if ((account_id >= 1000) && (account_id <= 9999))// 4 digits, account_id only
			{
				if (!accounts_list.Retrieve(account_id, account))
				{
					printAccountIdError(front_trns, account_id);
				}

				else if (accounts_list.Retrieve(account_id, account))
				{
					account->printAccountHistory();
				}
			}

			else if ((account_id >= 10000) && (account_id <= 99999)) // 5 digits, account_id + fund_id
			{
				fund_id = front_trns.getAccountID() % 10;
				account_id = front_trns.getAccountID() / 10;

				if (!accounts_list.Retrieve(account_id, account))
				{
					printAccountIdError(front_trns, account_id);
				}

				else if (accounts_list.Retrieve(account_id, account))
				{
					account->printFundHistory(fund_id);
				}
			}

			else
			{
				printAccountIdError(front_trns, account_id);
			}
		}

		transactions_list.pop();
	}
}

// Helper method to print error messages 
void Bank::printAccountIdError(Transaction front_trns, int account_id) const
{
	if (account_id < 1000 || account_id > 99999) // the range of valid accoutn&fund numbers 
	{
		cerr << "ERROR: Account " << account_id << " not valid." << endl;
	}
	else
	{
		cerr << "ERROR: Account " << account_id << " not found. Transaction " << front_trns << " refused." << endl;
	}
}

// Prints final balances for all open Accounts
void Bank::Display() const
{
	cout << "\nProcessing Done. Final Balances" << endl;
	accounts_list.Display();
}

