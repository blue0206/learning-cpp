#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	{
		//Fahrenheit = ((9 * Celsius) / 5) + 32.00; where 5 is divisor.
		//Create type-double variables for celsius, fahrenheit, and the divisor.
		double c, f;
		double divisor = 5;
		
		//Prompt user to input celsius value to be converted.
		cout << "Enter the celsius value to convert into fahrenheit: ";
		cin >> c;
		
		//Set the value of fahrenheit, f equal to expression.
		f = ((9 * c) / divisor) + 32.0;
		
		//Print the fahrenheit value.
		cout << "The fahrenheit value is: " << f << endl;
	}
	
	
	{
		//Celsius = ((5 * Fahrenheit) - 160) / 9; where 9 is divisor.
		//Create type-double variables for celsius, fahrenheit, and the divisor.
		double c, f;
		double divisor = 9;
		
		//Prompt the user to input fahrenheit value to be converted.
		cout << "Enter the fahrenheit value to convert into celsius: ";
		cin >> f;
		
		//Set the value of celsius, f equal to expression.
		c = ((5 * f) - 160) / divisor;
		
		//Print the celsius value.
		cout << "The celsius value is: " << c << endl;
	}
		
	return 0;
}







