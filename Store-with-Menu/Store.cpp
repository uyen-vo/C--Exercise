#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Store.h"
#include "Product.h"
#include "Customer.h"

Store::Store() {
	products;
	customers;
}

Customer Store::newCustomer(string first, string last, string cID) {
	double balance = 0;
	char input;
	string taken = "";
	string sameID = "";
	Customer cust(first, last, cID);

	for (int i = 0; i < customers.size(); i++) {
		if (customers.at(i).getID().compare(cID) == 0) {
			sameID = cID;
		}
		taken += customers.at(i).getID() + " ";
	}

	if (sameID == cID) {
		throw runtime_error("Those taken are: \n" + taken);
	}

	cout << "\nWould you also like to set their balance? (y/n)" << endl;
	cin >> input;
	if (input == 'y' || input == 'Y') {
		cout << "\nHow much would you like to set?" << endl;
		cin >> balance;
		cust.setBalance(balance);
		cout << "Balance now set to $" << cust.getBalance() << "\n\n";
	}

	customers.push_back(cust);

	return cust;
	;
}

Product Store::newProduct(string name, string pID, double priceW, double priceR) {
	char input;
	int inventory = 0;
	string taken = "";
	string sameID = "";
	Product prod(name, pID, priceW, priceR);

	for (int i = 0; i < products.size(); i++) {
		if (products.at(i).getID().compare(pID) == 0) {
			sameID = pID;
		}
		taken += products.at(i).getID() + " ";
	}

	if (sameID == pID) {
		throw runtime_error("Those taken are: \n" + taken);
	}

	cout << "\nWould you also like to set this product's stock? (y/n)" << endl;
	cin >> input;
	if (input == 'y' || input == 'Y') {
		cout << "\nHow much would you like to set?" << endl;
		cin >> inventory;
		prod.setStock(inventory);
		cout << "There is currently " << prod.getStock() << " units of " << name << "." << endl << endl;
	}
	products.push_back(prod);

	return prod;
}

void Store::transaction(string cID, string pID, int quantity) {
	double productCharge = 0.0;
	Product prod;
	int count = 0;

	//checking product availability
	if (checkProduct(quantity, pID)) {
		try {
			if (quantity < 0) {
				throw runtime_error("Quantity must be greater than 0 for a transaction.");
			}
			if (customers.size() == 0) {
				throw runtime_error("There are no customers.");
			}
			//finding what product
			for (int i = 0; i < products.size(); i++) {
				if (products.at(i).getID().compare(pID) == 0) {
					products.at(i).decreaseStock(quantity);
					productCharge = products.at(i).getPriceR()*quantity;
					prod = products.at(i);
				}
			}

			//finding which customer and charges
			for (int i = 0; i < customers.size(); i++) {
				if (customers.at(i).getID().compare(cID) == 0) {
					count--;
					customers.at(i).setCharged(productCharge);
					customers.at(i).addToHistory(prod);
				}
				count++;
			}


			if (count == customers.size()) {
				throw runtime_error("No customer exists.");
			}

		}
		catch (runtime_error &excpt) {
			cout << excpt.what() << endl;
			cout << "Please try again." << endl << endl;
		}

	}
	else {
		try {
			if (checkProduct(quantity, pID) == false) {
				throw runtime_error("Not enough in stock.");
			}
		}
		catch (runtime_error &excpt) {
			cout << excpt.what() << endl;
			if (prod.getStock() != 0) {
				cout << "There is only " << prod.getStock() << " units left of " << prod.getName() << endl << endl;
			}
		}
		rejectSale();
	}
}

bool Store::checkProduct(int quantity, string pID) {
	for (int i = 0; i < products.size(); i++) {
		if (products.at(i).getID().compare(pID) == 0)
		{
			if (quantity < products.at(i).getStock()) {
				return true;
			}
		}
	}

	return false;
}

void Store::rejectSale() {
	cout << "\nSale rejected; there is not enough product" << endl << endl;
}
void Store::payment(string cID, double price) {
	int count = 0;

	for (int i = 0; i < customers.size(); i++) {
		count++;
		if (customers.at(i).getID().compare(cID) == 0) {
			count--;
			try {
				if (price < 0) {
					throw runtime_error("Price must be greater than zero in order to pay.\n");
				}

				if (checkBalance(customers.at(i), price) && checkPayment(customers.at(i), price)) {
					customers.at(i).payCharged(price);
					cout << endl << customers.at(i).getFirstName() << " " << customers.at(i).getLastName()
						<< "'s new balance is $" << customers.at(i).getBalance() << endl << endl;
					if (customers.at(i).getCharged() == 0) {
						cout << "He/she has paid all his/her dues in full." << endl << endl;
					}
					else {
						cout << "He/she has $" << customers.at(i).getCharged() << " left that he/she owes." << endl << endl;
					}
				}

				else {
					if (checkBalance(customers.at(i), price) == false) {
						throw runtime_error("Insufficient funds in customer's account.\n");
					}
					if (checkPayment(customers.at(i), price) == false) {
						throw runtime_error("He/she is paying more than he/she is charged.\n");
					}
				}

				if (count == customers.size()) {
					throw runtime_error("No customer exists.");
				}
			}
			catch (runtime_error &excpt) {
				cout << excpt.what() << endl;
			}
		}

	}
}

//positive balance? sufficient funds
bool Store::checkBalance(Customer cust, double price) {
	if (cust.getBalance()>0 && cust.getBalance() >= price)
		return true;
	return false;
}

//checks if customer is paying within their charged amount
//prevents a negative charge
bool Store::checkPayment(Customer cust, double price) {
	if (price <= cust.getCharged())
		return true;
	return false;
}

void Store::setBalance(string cID, double amount) {
	int count = 0;
	for (int i = 0; i < customers.size(); i++) {
		if (customers.at(i).getID().compare(cID) == 0) {
			customers.at(i).setBalance(amount);
			count--;
		}
		count++;
	}

	if (count == customers.size()) {
		throw runtime_error("No customer exist.");
	}
}

void Store::newShipment(string pID, int quantity) {


	if (isProduct(pID))
	{
		for (int i = 0; i < products.size(); i++) {
			if (products.at(i).getID().compare(pID) == 0) {
				products.at(i).addStock(quantity);
				cout << "There are currently " << products.at(i).getStock() << " units of " << products.at(i).getName() << ".\n\n";
			}
		}

	}
	else {
		rejectShipment();
	}
}

bool Store::isProduct(string pID) {
	for (int i = 0; i < products.size(); i++) {
		if (products.at(i).getID().compare(pID) == 0) {
			return true;
		}
	}
	return false;
}

void Store::rejectShipment() {
	cout << "Shipment rejected; could not identify product" << endl << endl;
}

void Store::findAmountOwe(string cID) {
	for (int i = 0; i < customers.size(); i++) {
		if (customers.at(i).getID().compare(cID) == 0) {
			cout << "This customer owes a total of $" << customers.at(i).getCharged() << "." << endl << endl;
		}
	}
}

void Store::printCustomers(string cID) {
	int count = 0;
	for (int i = 0; i < customers.size(); i++) {
		if (customers.at(i).getID().compare(cID) == 0) {
			cout << "Customer information for ID number: " + cID + "\n";
			customers.at(i).printAll();
			count--;
		}
		count++;
	}

	if (count == customers.size()) {
		throw runtime_error("\nNo customer exists.\n\n");
	}

}

void Store::printProducts(string pID) {
	int count = 0;
	for (int i = 0; i < products.size(); i++) {
		if (products.at(i).getID().compare(pID) == 0) {
			cout << "Product information for ID number: " + pID + "\n";
			products.at(i).printAll();
			count--;
		}
		count++;
	}
	if (count == products.size()) {
		throw runtime_error("\nNo product exists.\n\n");
	}
}

void Store::printAll() {
	string output = "Information for all customers and products: \n";
	for (int i = 0; i < products.size(); i++) {
		products.at(i).printAll();
		cout << endl << endl;
	}

	for (int i = 0; i < customers.size(); i++) {
		customers.at(i).printAll();
		cout << endl << endl;
	}

}