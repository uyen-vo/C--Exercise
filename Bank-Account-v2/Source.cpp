#include <iostream>
#include <limits>
#include <fstream>
#include "Bank.h"
#include "SavingsAccount.h"

//FIX: if not enough parameters, give usage information -> how to continue
//FIX: if extra parameters, ignore

using namespace std;

void printMenu();
char getMenuSelection();
void addAccount(Bank& b, Account::type type);
void printAccount(Bank& b);
void processMenuSelection(char selection, Bank& b);
void makeDeposit(Bank& b);
void doWithdrawl(Bank& b);
void processInterest(Bank& b);

ifstream inFS;
ofstream outFS;
Bank bank;

int main(int argc, char** argv) {
	if(argc > 1){
		inFS.open(argv[1]);
	}
	else{
		cout << endl << "Usage: myprog.exe input.txt (output.txt)" << endl;
		return 1;
	}
	
	if(argc>2){
		outFS.open(argv[2]);
	}
	else
	{
		outFS.open("output.txt");
	}
	
   
	
	
	if (!outFS.is_open()) {
      outFS << "Could not open file \"" << argv[2] << "\"" << endl;
      return 1;
	}
   
	if (!inFS.is_open()) {
     outFS << "Could not open file \"" << argv[1] << "\"" << endl;
       
      return 1;
	}
  
	char choice = '0';
	while (!inFS.eof() && choice != 'X') {
		printMenu();
		choice = getMenuSelection();
		try {
			processMenuSelection(choice, bank);
		}
		catch (runtime_error& e) {
			outFS << endl << "Error: " << e.what() << endl;
		}
		catch (...) {
			outFS << endl << "Unknown error..." << endl;
		}
	}
	
	inFS.close();
}

void printMenu() {
	// outFS << endl;
	// outFS << "1: Add Checking Account" << endl;
	// outFS << "2: Add Savings Account" << endl;
	// outFS << "3: Show Account" << endl;
	// outFS << "4: Show All Accounts" << endl;
	// outFS << "5: Make a Deposit" << endl;
	// outFS << "6: Make a Withdrawl" << endl;
	// outFS << "7: Process Interest" << endl;
	// outFS << "X: Exit" << endl;
	// outFS << endl << "Please enter choice: ";
}

void processMenuSelection(char selection, Bank& bank) {
	switch (selection) {
	case '1':
		addAccount(bank, Account::CHECKING);
		break;
	case '2':
		addAccount(bank, Account::SAVINGS);
		break;
	case '3':
		printAccount(bank);
		break;
	case '4':
		outFS << endl << "Showing all accounts: " << endl;
		bank.printAccounts();
		break;
	case '5':
		makeDeposit(bank);
		break;
	case '6':
		doWithdrawl(bank);
		break;
	case '7':
		processInterest(bank);
	}
}

char getMenuSelection() {
	char ch;
	if(!(inFS >> ch))
		return 'X';
	//inFS.clear(); // unset failbit
	//inFS.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
	//outFS << ch << endl;
	return toupper(ch);
}

int getAccountNumber() {
	int accountNumber = 0;
	//outFS << "Enter Account Number: ";
	inFS >> accountNumber;
	//outFS << accountNumber << endl;
	//inFS.clear(); // unset failbit
	//inFS.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
	return accountNumber;
}

double getAmount() {
	double amount = 0;
	//outFS << "Enter Amount: ";
	inFS >> amount;
	//outFS << amount << endl;
	return amount;
}

void addAccount(Bank& b, Account::type type) {
	string ownerName;
	int accountNumber = 0;
	double interestRate = 0.0;
	int checkLimit = 0;

	accountNumber = getAccountNumber();

	//outFS << "Enter Account Owner's Name: ";
	//inFS >> interestRate;
	//outFS << ownerName << endl;

	switch (type) {
	case Account::SAVINGS:
		//outFS << "Enter Interest Rate: ";
		inFS >> interestRate;
		
		getline(inFS, ownerName);
		//outFS << interestRate << endl;
		b.addSavingsAccount(accountNumber, ownerName, interestRate);
		outFS << "Savings Account number " << accountNumber << " with interest rate " <<
		interestRate << " created for" << ownerName << endl;
		break;
	case Account::CHECKING:
		getline(inFS, ownerName);
		b.addCheckingAccount(accountNumber, ownerName);
		outFS << "Checking Account number " << accountNumber << " created for" << 
		ownerName << endl;
		break;
	}
}

void makeDeposit(Bank& b) {
	try{int c = getAccountNumber();
	double a = getAmount();
	if(a == 0.0)
		throw runtime_error("No amount provided");
	b.makeDeposit(c,a);
	}
	catch(runtime_error& excpt){
		outFS << excpt.what() << " for deposit" << endl;
		char d;
		inFS.clear(); // unset failbit
		inFS.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
		inFS >> d;
		if(!inFS >> d){
			d == 'X';
		}
		processMenuSelection(d, bank);
	}
}

void doWithdrawl(Bank& b) {
	try{
		int c = getAccountNumber();
	double a = getAmount();
	if(a == 0.0)
		throw runtime_error("No amount provided");
	b.doWithdrawl(c, a);
	}
	catch(runtime_error& excpt){
		outFS << excpt.what() << " for withdrawl"<< endl;
		char d;
		inFS.clear(); // unset failbit
		inFS.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
		if(!inFS >> d){
			d == 'X';
		}
		processMenuSelection(d, bank);
	}

}

void processInterest(Bank&  b) {
	try {
		Account* a = b.getAccount(getAccountNumber());
		SavingsAccount* s = dynamic_cast<SavingsAccount*>(a);
		s->processInterest();
	}
	catch (...) {
		outFS << "Wrong Account Type" << endl;
	}
}

void printAccount(Bank& b) {
	int accountNumber = 0;

//	outFS << "Enter Account Number: ";
	inFS >> accountNumber;
	//outFS << accountNumber << endl;
	outFS << "Printing account for account number: " << accountNumber << endl;
	b.printAccount(accountNumber);
}



