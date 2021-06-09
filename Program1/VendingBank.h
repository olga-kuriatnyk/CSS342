/*
	Olga Kuraitnyk 
	CSS342A
	Program 1: The Vending Bank
	The interface for a class which models the "bank" part of a Vending mashine which sells snacks.
*/

#pragma once
#include <string>
#include <vector>
using namespace std;

class VendingBank
{
public:
	//constructor
//	VendingBank();
	VendingBank(int id);
	VendingBank(int id, double totalCashEntered_);

	//getters-setters
	int getVendingBankID() const;
//	void setVendingBankID(int id);
	double getCustomerCash() const;
	void setCustomerCash(double totalCustomerCash_);

	//actions-verbs
	void displayMenu() const;
	void displayStock() const; 
	bool checkInStock(int vendingItemId) const;
	bool isEmpty() const;

	void addItem(int vendingItemId_);
	void addItem(int vendingItemId_, int quanity);

	bool choseItem(int vendingItemId_);
	bool choseItem(int vendingItemId_, int quanity);

	bool completeTransaction();
	bool cancelTransaction();
	int withdrawVendingBankCash();

private:

	double totalCustomerCash_;
	double totalVendingBankCash_;
	int vendingItemId_;
	int id_;

	vector<int> inventoryList;
	vector<int> chosenCustomerIteams;

	double returnMoney();
	int dispenceIteams();
};

