#include <iostream>

using namespace std;

int main()
{
	int c1 = 3;
	int c2 = 5;

	//Line 1
	cout << "      ";
	for (int i = 0; i < c1; i++)
	{
		cout <<"X ";
	}
	cout <<"\n";
	
	//Line 2
	cout << "     X";
	cout << "    X\n";	
	
	//Line 3-7
	for (int i = 0; i < c2; i++)
	{
		cout << "    X\n";
	}
	
	//Line 8
	cout << "     X";
	cout << "    X\n";
	
	//Line 9
	cout << "      ";
	for (int i = 0; i < c1; i++)
	{
		cout <<"X ";
	}
	cout <<"\n";
	
	return 0;
}