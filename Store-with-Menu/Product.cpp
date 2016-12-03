#include <iostream>
#include <string>

using namespace std;

#include "Product.h"

Product::Product() {
	name = "";
	pID = "";
	priceW = 0;
	priceR = 0;
	stock = 0;
	amountSold = 0;
}

Product::Product(string name, string pID, double priceW, double priceR) {
	this->name = name;
	this->pID = pID;
	this->priceW = priceW;
	this->priceR = priceR;
	amountSold = 0;
	stock = 0;
}

void Product::setName(string name) {
	this->name = name;
}

void Product::setID(string pID) {
	this->pID = pID;
}

void Product::setPriceW(double priceW) {
	this->priceW = priceW;
}

void Product::setPriceR(double priceR) {
	this->priceR = priceR;
}

string Product::getName() {
	return name;
}

string Product::getID() {
	return pID;
}

double Product::getPriceW() {
	return priceW;
}

double Product::getPriceR() {
	return priceR;
}

void Product::setStock(int quantity) {
	this->stock = quantity;
}

int Product::getStock() {
	return stock;
}

void Product::addStock(int quantity) {
	this->stock += quantity;
}

void Product::decreaseStock(int quantity) {
	this->stock -= quantity;
	amountSold += quantity;
}

int Product::getAmountSold() {
	return amountSold;
}

void Product::printAll() {
	cout << "Name: " << getName() << endl;
	cout << "Product ID: " << getID() << endl;
	cout << "Retail price: $" << getPriceR() << endl;
	cout << "Wholesale price: $" << getPriceW() << endl;
	cout << "Stock: " << getStock() << endl;
	cout << "Amount sold: " << getAmountSold() << endl;

	cout << endl;
}
