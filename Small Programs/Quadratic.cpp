#include <iostream>
using namespace std;

int main() {
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;

	double posRoot = 0.0;
	double negRoot = 0.0;
	double imaginaryA = 0.0; // a+bi
	double imaginaryB = 0.0; // a+bi
	double discrim = 0.0;
	char input = 'y';

	while (input == 'y' || input == 'Y') { 
		cout << "Enter in coefficients for a, b, and c to find the roots of the quadratic equation: (a should be non-zero)" << endl;
		cin >> a;
		cout << endl;
		cin >> b;
		cout << endl;
		cin >> c;
		cout << endl;

		discrim = pow(b, 2) - (4 * a*c);

		if (a == 0)
		{
			cout << "a should be non-zero." << endl;
		} //works

		else {
			if (discrim > 0) //checks if there is a negative under the square-root
			{
				posRoot = (-b + sqrt(discrim)) / (2 * a);
				negRoot = (-b - sqrt(discrim)) / (2 * a);
				cout << "The positive root is x = " << posRoot << "." << endl;
				cout << "The negative root is x = " << negRoot << "." << endl;
			}

			else {
				discrim *= -1;
				imaginaryA = (-b) / (2 * a);
				imaginaryB = sqrt(discrim) / (2 * a);
				cout << "The positive imaginary root is x = " << imaginaryA << " + "
					<< imaginaryB << "i." << endl;
				cout << "The negative imaginary root is x = " << imaginaryA << " - "
					<< imaginaryB << "i." << endl;
			}
	}
		cout << endl << "Would you like to solve another? Answer y / n." << endl;
		cin >> input;
		cout << endl;
	
	}
	

	





}