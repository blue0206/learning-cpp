// Coded by Aayush. Date- 11 September 2022. 
// This program finds the value at which Fahrenheit and Celsius are same, using for loop.
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	double celsius, fahrenheit;
	const double divisor = 5, multiplier = 9;
	
	for (celsius = 100; celsius < 101; celsius--)
	{
		fahrenheit = ((celsius * multiplier) / divisor) + 32;
		if (fahrenheit == celsius)
		{
			break;
		}
	}
	cout << "Fahrenheit and Celsius are of same value at " << celsius << endl;
	
	return 0;
}