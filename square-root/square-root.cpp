#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	cout << "The following program finds the value of a square root." << endl;
	
	double n;
	cout << "Enter the square root: ";
	cin >> n;
	
	double guess;
	cout << "Enter your guess for what the answer is: ";
	cin >> guess;
	
	double r;
	for (int i = 0; i < 100 ; i++) {
		r = n / guess;
		guess = (guess + r) / 2;
	}
	
	cout << "The answer is " << guess << endl;
	
	return 0;
}