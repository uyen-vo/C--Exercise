//Uyen Vo
//CSCE 222-501
//Due: 2016/02/28
//Extra Credit Homework 1

/*Analyze the complexity of the chosen program in a way similar to how we
did in class (refer to the lecture slides #35–45 in the complexity.pdf file),
and write the complexity of each component as well as the total complexity
as line-by-line comments (as shown in the lecture slide #45) and print
out the whole file
*/

//Sources: https://www.daniweb.com/programming/computer-science/threads/44665/calculate-time-complexity-of-the-algorithm
		// Maxwell Melcher
		// Complexity PPT slides

#include <iostream>
using namespace std;

int increment(int num){ //parameter assignment O(1)
	num++; 	//elementary operation because it is arithmetic
				//O(1) time and total time because this is the only component
	return num; //return is O(1)
	//total is O(1) + O(1) + O(1) = O(1)
}

int main() {
	int square = 0; //elementary operation, assignment, O(1)
	double numWheat = 0; //elementary operation, assignment, O(1)
	double totalWheat = 0; //elementary operation, assignment, O(1)
	char answer = 'y'; //elementary operation, assignment, O(1)
	double input = 0; //elementary operation, assignment, O(1)
	
	//total time so far is 4 * O(1) = O(1)
	
	while (answer == 'y' || answer == 'Y') {
		square = 1; //elementary operation, assignment, O(1)
		numWheat = 1; //elementary operation, assignment, O(1)
		cout << "How many grains of wheat would you like?" << endl; //cout operation is constant time O(1)
		cin >> input; //cin operation is constant time O(1)
		
		//this "block" is 4 * O(1) = O(1)
		
		while (square <= 64) //bool expression is elem operation, comparison, O(1)
		{
			if (input < 0) //bool expression is elem operation, comparison, O(1)
			{
				cout << "Your amount of grains is negative." << endl; //cout is O(1)
				break;
				
				//total time for this block O(1)
			}
			else{
				totalWheat += numWheat; //elementary operation, arithmetic O(1)
				numWheat *= 2; //elementary operation, arithmetic O(1)
				
				//total time for this block 2 * O(1) = O(1)
			}
			
			//the Big Oh for if-else is O(1) + O(1) = O(1) from the bool expression + the greater
			//time complexity between the two blocks of the if-else, which is O(1) since they're
			//both equal to one another
			//O(1)+O(max(O(1),O(1)))
			
			if (totalWheat >= input) //bool expression is elem operation, comparison, O(1)
			{
				cout << "You would need at least " << square << " square(s) for " << input << " grains of wheat." << endl;
				break;
				
				//cout is O(1)
				//total time for this block is O(1)
			}

			increment(square); //function call
			//time to assign param = O(1) because it is num = square
			//time to execute the block in the function is O(1) because it is arithmetic
			//time of f(params) = O(assign param + block) = O(constant + constant) = O(1) for the function
		}
		//end of while loop
		//starts at square = 1 to square = 64; (b-a+1) = (64-1+1) = 63 times
		//the total of the inside of the while loop is:
		//initial comparison/condition + if-else 			+ if 		+ function call
		//O(1)						+	 O(1)			 	+ O(1) 		+ O(1)
		//while loop total time = 64*O(1)
		
		if (input > totalWheat) { //bool expression is elem operation, comparison, O(1)
			cout << "There are not enough squares for " << input << " grains of wheat." << endl;
			//cout is O(1)
		}
		//total for this block is O(1) + O(1) for the bool expression and the block
		
		cout << endl << "Would you like to try again?" << endl; //cout is O(1)
		cin >> answer; //cin is O(1)
	}
	//this while loop is only to allow testing multiple numbers in my old program
	
}