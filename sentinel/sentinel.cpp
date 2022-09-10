#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	//This program displays how we use a sentinel value to exit loops.
	int sum = 0;
	cout << "This program finds sum of even numbers entered by user.\n";
	cout << "Enter an uneven number to stop calculation." << endl;
	cout << "Enter even number: ";
	int next; 
	cin >> next;
	while ((next % 2) == 0) 		//next not 'even' is the sentinel value.
	{
		sum = sum + next;
		cout << "Enter next even number: ";
		cin >> next;
	}
	cout << "The sum of even numbers entered by user is: " << sum << endl;
	
	return 0;
}
