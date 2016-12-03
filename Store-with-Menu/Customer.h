#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

using namespace std;

#include "Product.h"

class Customer {
public:
	Customer();
	Customer(string firstName, string lastName, string cID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setID(string cID);
	string getFirstName();
	string getLastName();
	string getID();
	void setBalance(double balance);
	double getBalance();
	void payCharged(double payment);
	void setCharged(double charged);
	double getCharged();
	void addToHistory(Product prod);
	vector<Product> getHistory();
	void printAll();

private:
	string firstName;
	string lastName;
	string cID;
	vector<Product> historyBought;
	double balance;
	double charged;
};

#endif