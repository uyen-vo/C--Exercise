#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	double seed;
	vector <int> code(4);
	vector <int> test(4);
	vector <int> guess;
	int numGuessed = 0;
	char answer = 'y';
	int numCows;
	int numBulls;
	int count;

	while (answer == 'y' || answer == 'Y') {
		numCows = 0;
		numBulls = 0;
		guess.resize(4);
		cout << "Please enter a random integer: ";
		cin >> seed;

		seed = (int)seed; // in case a double is inputted
		srand(seed);


		for (int i = 0; i < 4; i++) { 
			code.at(i) = rand() % 10;
			do {
				count = 0;
				for (int j = 0; j < i; j++) {
					if (code.at(i) == code.at(j)) {
							/*  checks for repeating number
								makes sure that each is distinct
								TEST CASES: seed of 55 and 666 */
						
						code.at(i)++;
						if (code.at(i) == 10)
						{
							code.at(i) = 0;
						}
						count++;
					}
				}

			} while (count > 0);


			/*cout << code.at(i);     
					shows the code*/
		}

		cout << endl;

		while (guess != code)
		{
			do{
				numCows = 0;
				numBulls = 0;
			cout << "Guess the four-digit number. Each number is distinct. " << endl;
			cin >> numGuessed;
			cout << endl;

			if (numGuessed >= 10000)
			{
				cout << "Enter a four-digit number. " << endl;
				cin >> numGuessed;
				cout << endl;
				
			}

				for (int i = 3; i >= 0; i--) { //puts four-digit number in vector, anything less than 1000 will have preceding 0's
					guess.at(i) = numGuessed % 10;
					numGuessed /= 10;

				}
				test = guess;
				sort(test.begin(), test.end());
				test.erase(unique(test.begin(), test.end()), test.end());

				if (test.size() < 4) {
					cout << "Please enter four distinct numbers. " << endl;
					break;
					
				}

				if (guess == code)
				{
					cout << "4 bulls! The code was ";
					for (int i = 0; i < 4; i++) {
						cout << guess.at(i);
					}
					cout << "!" << endl;
					break;
				}
				else {
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (guess.at(i) == code.at(j)) {
								if (i == j) {
									numBulls++;
								}
								else {
									numCows++;
								}
							}

						}
					}
				}
			
			cout << numBulls << " bulls and " << numCows << " cows!" << endl << endl;
			} while (numBulls != 4);
		}

		cout << endl;
		guess.clear();
		cout << "Would you like to play again?" << endl;
		cin >> answer;
		cout << endl;
	}



}