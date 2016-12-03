#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	
	vector<int> counts;
	int min = 0;
	int max = 0;
	int numGen = 0;
	int numSeed = 0;
	int randNum = 0;
	char answer = 'y';

	while (answer == 'y' || answer == 'Y') { //reprompt

		cout << "Enter the Minimum Value: ";
		cin >> min;
		cout << "Enter the Maximum Value: ";
		cin >> max;
		cout << "Enter the number of random numbers to generate: ";
		cin >> numGen;
		cout << "Enter the random seed: ";
		cin >> numSeed;
		cout << endl << endl;

		//accomodation for max being less than min
		//and numGen being negative
		if (max < min || numGen < 0)
		{
			cout << "An error has occurred. Would you like to try again? Enter 'y' or 'n'" << endl;
		}
		else {
			counts.resize(max - min + 1);
			srand(numSeed);

			//if numGen is less than 10
			if (numGen < 10)
			{
				cout << "First " << counts.size() << ": ";
				for (int i = 0; i < numGen; i++)
				{
					randNum = (rand() % (max - min + 1)) + min;
					cout << randNum << " ";
				}
			}

			else {
				//first 10 "random" numbers
				cout << "First 10: ";


				for (int i = 0; i < 10; i++) {

					randNum = (rand() % (max - min + 1)) + min;
					cout << randNum << " ";

				}

			}
			cout << endl;

			//counting
			srand(numSeed); // resets the seed to start over for counting purposes
			for (int i = 0; i < numGen; i++)
			{

				randNum = (rand() % (max - min + 1)) + min;
				for (int j = min; j <= max; j++)
				{
					if (randNum == j)
					{
						//works for negative min/maxes
						counts.at(j - min) += 1;
					}
				}
			}

			cout << endl << "Counts: " << endl;
			for (int i = 0; i < counts.size(); i++)
			{
				cout << min << ": " << counts.at(i) << endl;
				min++;

			}
			//reset vector to not accumulate onto the previous counts
			counts.resize(0);

			cout << endl << "Do you want to run another set of tests? Enter 'y' or 'n'" << endl;
		}
		cin >> answer;
		cout << endl;
	}
}
