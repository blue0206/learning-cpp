//Coded by Aayush Rai on 19 September 2022.
//This program is only to be used by a programmer, NOT USER-FRIENDLY!
//This program solves questions implementing NEWTON-RAPHSON METHOD.
//You'll need to edit the code at various places to use this program according to your needs.

//f_of_x is f(x), derivative is f'(x), n is approximation number

//The formula is x(n+1) = xn - (f(xn)/f'(xn)) ; where n is the nth 'x'.
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(8);				//Set precision according to the needs of the question.
	
	//Next we input the initial value (x), f(x), and f'(x). Calculate f(x) and f'(x) yourself.
	double x = 2,       		  						
		   f_of_x = (pow(x,8)) - 500.0,
		   derivative = (pow(x,7)) * 8.0,
		   divisor = f_of_x / derivative;					//Put value of f(x)/f'(x) in divisor for making code readable.
		   
	double equalityCheck,			//Checks if the value of new 'x' is equal to the previous one.
		   result;			
	
	int approximation;   			//The'x' at which result was obtained a.k.a the nth 'x'. Is equal to 'n'.
	
	x = x - divisor;				//Calculation of x1
	
	for (int n = 1; n > 0; n++)                   //Set limit of n according to the approximation you need. Like n<5 for x4 (4th x).
	{
		equalityCheck = x;
		
		f_of_x = (pow(x,8)) - 500.0;						//The divisor arguments are calculated again to avoid logic error.
		derivative = (pow(x,7)) * 8.0;			
		divisor = f_of_x / derivative;								
		
		x = equalityCheck - divisor;
		
		if (x == equalityCheck)					//Set condition according to the answer you need.
		{
			result = x;
			approximation = n;
			cout << "The nearest answer is approximation "; 
			cout << approximation << " which equals:\n"; 
			cout << result << endl;
			break;
		}
	}

	return 0;
}
