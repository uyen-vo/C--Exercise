#include <iostream>
#include <string>
#include <sstream>


using namespace std;

bool SameOrNot(string word) {

	int start = 0;
	int end = word.size();
	string cutup = "";
	string firstLetter = word.substr(start, start + 1);
	string lastLetter = word.substr(word.size() - 1);

	//base case
	if (word.size() == 1||word.size() == 0) {
		return true;
	}
	
	//base case no.2
	else if (word.size() == 2)
	{
		if (firstLetter.compare(lastLetter)==0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	//recursive code
	else if (firstLetter.compare
		(lastLetter)==0) {

		cutup = word.substr(start + 1,word.size()-2);
		SameOrNot(cutup);
	}

	else {
		
		return false;
	}
}



int main() {
	char answer = 'y';
	int  notEqual = 0;

	while (answer == 'y' || answer == 'Y') {
		string input = "";
		bool outcome = true;
		int sum1 = 0;
		int sum2 = 0;

		cout << "Enter a word: ";
		cin >> input;
		cout << endl;

		//check ascii values; prevents unnecessary recursion

		if (input.size() % 2 == 0) {
			for (int i = 0; i < input.size() / 2; i++) {
				sum1 += input.at(i);
				sum2 += input.at(i + (input.size() / 2));
			}

			if (sum1 != sum2) {
				outcome = false;
				notEqual = 1;
			}

			
		}
		else if (input.size() % 2 == 1) {
			for (int i = 0; i <= input.size() / 2; i++)
			{
				sum1 += input.at(i);
				sum2 += input.at(i + (input.size() / 2));
			}
			if (sum1 != sum2) {
				outcome = false;
				notEqual = 1;
			}
		}
		if (notEqual != 1) {
			
			outcome = SameOrNot(input);
		}
		

		if (outcome) {
			cout << "\"" << input << "\"" << " is a palindrome." << endl << endl;
		}
		if(!outcome){
			cout << "\"" << input << "\"" << " is NOT a palindrome." << endl << endl;

		}
		

		cout << "Do you want to check another? (y/n)" << endl;
		cin >> answer;
		cout << endl;
	}
	

}