#include <iostream>
using namespace std;

int main() {

	int input = 0;
	char answer = 'y';
	while (answer == 'y' || answer == 'Y') {
		cout << "Please enter an integer:" << endl;
		cin >> input;

		if (input % 2 == 0) {
			cout << "Even" << endl << endl;
		}
		else {
			cout << "Odd" << endl << endl;
		}


		cout << "Would you like to try another integer? (y / n)" << endl;
		cin >> answer;
		cout << endl;
	}


	return 0;
}
