#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iomanip>
#include "Customer.h"
#include "Product.h"
#include "Store.h"

using namespace std;

//NOTE: the 'balance' in my code refers to the amount the customer has (like a checking account)
//the 'amount owed' is the number that is referred to as 'balance' in Homework 7 (like a credit card)
//a 'payment' deduces the 'amount owed' and money from the customer's 'balance'
//this does not affect the code for the purposes of the assignment

int main() {
	char choice = '0';
	char enter = 'n';
	Store onlineStore;
	Customer c;
	Product p;

	cout << "Would you like to enter the store? (y/n)" << endl;
	cin >> enter;
	cout << endl;

	while (enter == 'y' || enter == 'Y') {
		cout << "What would you like to do? (1-9)" << endl << endl;
		cout << "1. Add a product" << endl;
		cout << "2. Add a customer" << endl;
		cout << "3. Take a new shipment" << endl;
		cout << "4. Set a customer's balance" << endl;
		cout << "5. Make a transaction (customer is buying)" << endl;
		cout << "6. Accept a payment from customer" << endl;
		cout << "7. Find total charge of a customer" << endl;
		cout << "8. Show customer information" << endl;
		cout << "9. Show product information." << endl;
		cout << "0. Show all product and customer information." << endl;
		cout << "X. Exit store." << endl << endl;

		cin >> choice;

		cout << endl;

		switch (choice) {
		case '1': {
			string name;
			string pID;
			double priceW;
			double priceR;

			cout << "What is this product's name?" << endl;
			cin >> name;
			cout << "\nWhat is this product's ID?" << endl;
			cin >> pID;
			cout << "\nWhat is this product's wholesale price?" << endl;
			cin >> priceW;
			cout << "\nWhat is this product's retail price?" << endl;
			cin >> priceR;

			try {
				p = onlineStore.newProduct(name, pID, priceW, priceR);
			}
			catch (runtime_error &excpt) {
				cout << "\nThis product ID has already been taken." << endl;
				cout << "Please try again with a different ID." << endl;
				cout << excpt.what() << endl << endl;
			}

			break;
		}

		case '2': {
			string first, last, cID;
			cout << "What is this customer's first name?" << endl;
			cin >> first;
			cout << "\nWhat is this customer's last name?" << endl;
			cin >> last;
			cout << "\nWhat is this customer's ID number?" << endl;
			cin >> cID;

			try {
				c = onlineStore.newCustomer(first, last, cID);
			}
			catch (runtime_error &excpt) {
				cout << "\nThis customer ID has already been taken." << endl;
				cout << "Please try again with a different ID." << endl;
				cout << excpt.what() << endl << endl;
			}

			break;
		}

		case '3': {
			string pID;
			int quantity;
			cout << "Enter the product ID for the new shipment: " << endl;
			cin >> pID;
			cout << "\nEnter the quantity to be shipped: " << endl;
			cin >> quantity;
			cout << endl;

			onlineStore.newShipment(pID, quantity);
			
			break;
		}

		case '4': {
			string cID;
			double amount;
			cout << "Enter the customer ID for the new balance: " << endl;
			cin >> cID;
			cout << "\nHow much would you like to set his/her balance to?" << endl;
			cin >> amount;
			cout << endl;
			
			try {
				onlineStore.setBalance(cID, amount);
			}
			catch (runtime_error &excpt) {
				cout << excpt.what() << endl << endl;
			}
			
			break;
		}

		case '5': {
			string cID;
			string pID;
			int quantity;
			
			cout << "Enter the ID of the purchaser: " << endl;
			cin >> cID;
			cout << "\nEnter the ID of the desired product: " << endl;
			cin >> pID;
			cout << "\nEnter the quantity desired: " << endl;
			cin >> quantity;
			cout << endl;
			onlineStore.transaction(cID, pID, quantity);

			break;
		}

		case '6': {
			string cID;
			double payment;
			cout << "Enter the ID of the paying customer: " << endl;
			cin >> cID;
			cout << "How much are they paying?" << endl;
			cin >> payment;

			onlineStore.payment(cID, payment);
			break;
		}

		case '7': {
			string cID;
			cout << "Enter the ID of the customer to find what he/she owes: " << endl;
			cin >> cID;
			cout << endl;

			onlineStore.findAmountOwe(cID);

			break;
		}
		case '8': {
			string cID;
			cout << "Enter the customer ID to show information: " << endl;
			cin >> cID;
			cout << endl;

			try {
				onlineStore.printCustomers(cID);
			}
			catch (runtime_error &excpt) {
				cout << excpt.what();
			}
			
			break;
		}
		case '9': {
			string pID;
			cout << "Enter the product ID to show information: " << endl;
			cin >> pID;
			cout << endl;

			try {
				onlineStore.printProducts(pID);
			}
			catch (runtime_error &excpt) {
				cout << excpt.what();
			}

			break; 
		}

		case '0': {
			onlineStore.printAll();
			break;
		}

		case 'X': {
			char input;
			cout << "Are you sure you would like to exit the store? (y/n)" << endl;
			cin >> input;
			if (input == 'y' || input == 'Y') {
				enter = 'n';
			}

			break;
		}
		case 'x': {
			char input;
			cout << "Are you sure you would like to exit the store? (y/n)" << endl;
			cin >> input;

			if (input == 'y' || input == 'Y') {
				enter = 'n';
			}

			break;
		}
		}

	}
}