#include "CheckingAccount.h"
#include <iostream>
#include <limits>

CheckingAccount::CheckingAccount
	(int accountNumber, string name) :
	Account(accountNumber, name) {}

string CheckingAccount::getType() {
	return "Checking";
}
