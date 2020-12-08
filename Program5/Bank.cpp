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

		if (trns_type == 'O')
		{
			string last_name, first_name;
			parseLine >> last_name >> first_name >> account_id;
			Transaction add_to_queue(trns_type, last_name, first_name, account_id);
			transactions_list.push(add_to_queue);
		}

		else if (trns_type == 'D' || trns_type == 'W')
		{
			parseLine >> account_id >> amount;
			fund_id = account_id % 10;
			account_id = account_id / 10;
			Transaction add_to_queue(trns_type, account_id, fund_id, amount);
			transactions_list.push(add_to_queue);
		}

		else if (trns_type == 'T')
		{
			parseLine >> account_id >> amount >> transfer_account_id;
			fund_id = account_id % 10;
			account_id = account_id / 10;
			transfer_fund_id = transfer_account_id % 10;
			transfer_account_id = transfer_account_id / 10;
			Transaction add_to_queue(trns_type, account_id, fund_id, amount, transfer_account_id, transfer_fund_id);
			transactions_list.push(add_to_queue);
		}

		else
		{
			cout << "UNKNOWN TRANSACTION TYPE" << endl;
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
		else if (front_trns.getTransactionType() == 'D') // TODO: implement 
		{
			int account_id = front_trns.getAccountID();
			int fund_id = front_trns.getFundID();
			int ammount_to_deposit = front_trns.getAmount();
			Account* account;
		
		}
		else if (front_trns.getTransactionType() == 'W') // TODO: implement 
		{

		}
		else if (front_trns.getTransactionType() == 'T') // TODO: implement 
		{

		}
		else if (front_trns.getTransactionType() == 'H') // TODO: implement 
		{

		}

		transactions_list.pop();
	}
}
