#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>

using namespace std;

#include "Product.h"
#include "Customer.h"

class Store {
public:
	Store();
	Customer newCustomer(string first, string last, string cID);
	Product newProduct(string name, string pID, double priceW, double priceR);

	void transaction(string cID, string pID, int quantity);
	bool checkProduct(int quantity, string pID);
	void rejectSale();

	void payment(string cID, double price);
	bool checkBalance(Customer cust, double price);
	bool checkPayment(Customer cust, double price);
	void setBalance(string cID, double amount);

	void newShipment(string pID, int quantity);
	bool isProduct(string pID);
	void rejectShipment();

	void findAmountOwe(string cID);

	void printCustomers(string cID);
	void printProducts(string pID);

	void printAll(); //loop thru and use each object's printAll() function

private:
	vector<Product> products;
	vector<Customer> customers;
};

#endif