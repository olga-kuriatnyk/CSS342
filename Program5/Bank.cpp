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

		if (trns_type == 'O' || trns_type == 'o')
		{
			string last_name, first_name;
			parseLine >> last_name >> first_name >> account_id;
			Transaction add_to_queue(trns_type, last_name, first_name, account_id);
			transactions_list.push(add_to_queue);
		}

		else if (trns_type == 'D' || trns_type == 'W' || trns_type == 'd' || trns_type == 'w')
		{
			parseLine >> account_id >> amount;
			fund_id = account_id % 10;
			account_id = account_id / 10;
			Transaction add_to_queue(trns_type, account_id, fund_id, amount);
			transactions_list.push(add_to_queue);
		}

		else if (trns_type == 'T' || trns_type == 't')
		{
			parseLine >> account_id >> amount >> transfer_account_id;
			fund_id = account_id % 10;
			account_id = account_id / 10;
			transfer_fund_id = transfer_account_id % 10;
			transfer_account_id = transfer_account_id / 10;
			Transaction add_to_queue(trns_type, account_id, fund_id, amount, transfer_account_id, transfer_fund_id);
			transactions_list.push(add_to_queue);
		}

		else if (trns_type == 'H' || trns_type == 'h')
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

void Bank::ProcesTransactions()
{
	while (!transactions_list.empty())
	{
		Transaction front_trns = transactions_list.front();

		if (front_trns.getTransactionType() == 'O')
		{
			Account* account = new Account(front_trns.getFirstName(), front_trns.getLastName(), front_trns.getAccountID());
			accounts_list.Insert(account);
		}

		else if (front_trns.getTransactionType() == 'D') // TODO: test
		{
			int account_id = front_trns.getAccountID();
			int fund_id = front_trns.getFundID();
			int deposit_amount = front_trns.getAmount();
			Account* account = NULL;
			if (accounts_list.Retrieve(account_id, account))
			{
				account->depositAmount(fund_id, deposit_amount);
				account->recordTransaction(front_trns, fund_id);
			}
			else if (!accounts_list.Retrieve(account_id, account))
			{
				cerr << "ERROR: Account " << account_id << " not found. Transaction refused." << endl;
			}
		}

		else if (front_trns.getTransactionType() == 'W') // TODO: test 
		{
			int account_id = front_trns.getAccountID();
			int fund_id = front_trns.getFundID();
			int withdraw_amount = front_trns.getAmount();
			Account* account = NULL;
			if (accounts_list.Retrieve(account_id, account))
			{
				account->withdrawAmount(fund_id, withdraw_amount, front_trns);
			}
			else if (!accounts_list.Retrieve(account_id, account))
			{
				cerr << "ERROR: Account " << account_id << " not found. Transaction refused." << endl;
			}
		}

		else if (front_trns.getTransactionType() == 'T') // TODO: test
		{
			int account_id = front_trns.getAccountID();
			int fund_id = front_trns.getFundID();

			int transfer_account_id = front_trns.getTransferAccountID();
			int transfer_fund_id = front_trns.getTransferFundID();

			int amount = front_trns.getAmount();

			Account* to, * from;

			if (accounts_list.Retrieve(account_id, to) && accounts_list.Retrieve(transfer_account_id, from))
			{
				if (to->withdrawAmount(fund_id, amount, front_trns))
				{
					from->depositAmount(transfer_fund_id, amount);
					from->recordTransaction(front_trns, transfer_fund_id);
				}
				else
				{
					//cerr
					cerr << "ERROR: Not Enought Funds to Transer " << amount << " from " << from->getAccountID() << from->getFundID() << " to " << to->getAccountID() << to->getFundID() << endl;
					Transaction trns('T', account_id, fund_id, amount, transfer_account_id, transfer_fund_id, "(Failed)");
					from->recordTransaction(trns, transfer_fund_id);
				}
			}
			else if (!accounts_list.Retrieve(account_id, to))
			{
				cerr << "ERROR: Account " << account_id << " not found. Transaction refused." << endl;
			}
			else if (!accounts_list.Retrieve(transfer_account_id, to))
			{
				cerr << "ERROR: Account " << transfer_account_id << " not found. Transaction refused." << endl;
			}
		}

		else if (front_trns.getTransactionType() == 'H') // TODO: test
		{
			if ((front_trns.getAccountID() >= 10000) && (front_trns.getAccountID() <= 99999)) // account_id + fund_id
			{
				Account* account;
				int fund_id = front_trns.getAccountID() % 10;
				int account_id = front_trns.getAccountID() / 10;
				if (accounts_list.Retrieve(account_id, account))
				{
					account->printFundHistory(fund_id);
				}
				else if (!accounts_list.Retrieve(account_id, account))
				{
					cerr << "ERROR: Account " << account_id << " not found. Transaction refused." << endl;
				}
			}

			else if ((front_trns.getAccountID() >= 1000) && (front_trns.getAccountID() <= 9999)) // 4 digirs, account_id only
			{
				Account* account;
				int account_id = front_trns.getAccountID();
				if (accounts_list.Retrieve(account_id, account))
				{
					account->printAccountHistory();
				}
				else if (!accounts_list.Retrieve(account_id, account))
				{
					cerr << "ERROR: Account " << account_id << " not found. Transaction refused." << endl;
				}
			}
		}

		transactions_list.pop();
	}
}

void Bank::Display() const
{
	cout << "\nProcessing Done. Final Balances" << endl;
	accounts_list.Display();
}

