#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

#include <string>

class Product {
public:
	Product();
	Product(string name, string pID, double priceW, double priceR);
	void setName(string name);
	void setID(string pID);
	void setPriceW(double priceW);
	void setPriceR(double priceR);
	string getName();
	string getID();
	double getPriceW();
	double getPriceR();
	void addStock(int quantity);
	void decreaseStock(int quantity);
	void setStock(int quantity);
	int getStock();
	int getAmountSold();
	void printAll();

private:
	string name;
	string pID;
	double priceW;
	double priceR;
	int stock;
	int amountSold;
};


#endif