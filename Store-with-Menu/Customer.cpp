#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Customer.h"
#include "Product.h"

Customer::Customer() {
	firstName = "";
	lastName = "";
	cID = "";
	balance = 0;
	charged = 0;
}


Customer::Customer(string firstName, string lastName, string cID) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->cID = cID;
	balance = 0;
	charged = 0;
}

void Customer::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Customer::setLastName(string lastName) {
	this->lastName = lastName;
}

void Customer::setID(string cID) {
	this->cID = cID;
}

string Customer::getFirstName() {
	return firstName;
}

string Customer::getLastName() {
	return lastName;
}

string Customer::getID() {
	return cID;
}

void Customer::setBalance(double balance) {
	this->balance = balance;
}

double Customer::getBalance() {
	return balance;
}

void Customer::payCharged(double payment) {
	this->charged -= payment;
	balance -= payment;
}

void Customer::setCharged(double charged) {
	this->charged += charged;
}

double Customer::getCharged() {
	return charged;
}

void Customer::addToHistory(Product prod) {
	historyBought.push_back(prod);
}
vector<Product> Customer::getHistory() {
	return historyBought;
}

void Customer::printAll() {
	cout << "Name: " << getFirstName() << " " << getLastName() << endl;
	cout << "Customer ID: " << getID() << endl;
	cout << "Balance: $" << getBalance() << endl;
	cout << "Amount owed: $" << getCharged() << endl;
	cout << "History bought: " << endl;

	for (int i = 0; i < getHistory().size(); i++) {
		cout << " - " << getHistory().at(i).getName() << endl;
	}

	if (getHistory().size() == 0) {
		cout << "No purchases yet." << endl;
	}

	cout << endl;
}

