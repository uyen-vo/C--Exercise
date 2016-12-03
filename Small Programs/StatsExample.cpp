#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int userIn = 0;

	cout << "Enter integers and enter a letter when done." << endl;
	// get input from user
	// cin >> userIn will evaluate to false to exit loop
	while (cin >> userIn) {
		v.push_back(userIn);
	}

	sort(v.begin(), v.end()); // Sort

							  // set min to first element in list since list is sorted
	int minVal = v.at(0);
	// set max to last element in list since list is sorted (note the -1)
	int maxVal = v.at(v.size() - 1);
	// since the loop starts looking at index 1, 
	//   initialize sum to the first element in list
	int sum = v.at(0);

	double median;
	// don't forget this is integer division
	if (v.size() % 2 == 0) { // even
		median = (v.at(v.size() / 2 - 1) + v.at(v.size() / 2)) / 2.0;
		//        ^index of first      ^index of second
	}
	else { // odd
		median = v.at(v.size() / 2);
	}

	/*
	To calculate the mode we'll track two things
	1. the current candidate for mode (curMode/curCount)
	2. the current winner for mode (mode/modeCount)
	*/
	int curMode = v.at(0);
	int curCount = 1;

	int mode = v.at(0);
	int modeCount = 1;
	vector<int> modes;
	int maxMode = 0;

	for (int i = 1; i < v.size(); ++i) {
		/*
		-- If we weren't doing the sort to find median and mode,
		this code would be better, but since we already had
		to sort, we'll take advantage of the sorted list.
		if (v.at(i) < minVal) {
		minVal = v.at(i);
		}
		if (v.at(i) > maxVal) {
		maxVal = v.at(i);
		}
		*/
		sum += v.at(i); // Increase sum by amount of current value

		if (curMode == v.at(i)) { // value is same as current mode candidate
			curCount++; // increment the count by 1
		}
		else { // value is a new candidate for mode
			if (curCount > modeCount) { // current candidate has a larger count
				mode = curMode; // set current candidate to mode winner
				modeCount = curCount; // set candidate count to mode count

			}

			// regardless of a new winner,
			// new candidate
			curMode = v.at(i); // set current value to be the new candidate for mode
			curCount = 1; // set candidate count to 1 for this occurrence

		}
	}
	curMode = v.at(0);
	curCount = 0;

	
	for (int j = 0; j < v.size(); j++) {
		for (int i = 0; i < v.size(); i++) {
			if (v.at(j) == v.at(i)) {
				curCount++;
			}
		}
		if (curCount == modeCount) {
			modes.push_back(v.at(j));
		}

		curCount = 0;
		
	}

	sort(modes.begin(), modes.end());
	modes.erase(unique(modes.begin(), modes.end()), modes.end());

	// Output results
	cout << "Your numbers are: ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	cout << "Max: " << maxVal << endl;
	cout << "Min: " << minVal << endl;
	cout << "Average: " << (static_cast<double>(sum) / v.size()) << endl;
	cout << "Median: " << median << endl;
	cout << "Mode: ";
	for (int i = 0; i < modes.size(); i++)
	{
		cout << modes.at(i) << " ";
	}
	cout << "(" << modeCount << ")" << endl;

	system("pause");
}