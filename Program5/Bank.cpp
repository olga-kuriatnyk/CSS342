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
		cout << "Cannot Open!" << endl;
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
		parseLine >> trns_type;

		if (trns_type == 'O')
		{

		}
		else if (trns_type == 'D')
		{

		}
		else if (trns_type == 'W')
		{

		}
		else if (trns_type == 'T')
		{

		}
		else
		{
			cout << "Unknown transaction type" << endl;
		}
	}

	//return false;
}

void Bank::ProcesTransactions()
{
}

