#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() 
{
	//Calculate velocity of sound in air across a temperature range.
	//Velocity = 331.3 + 0.61 * airTemperature; where we'll take 331.3 as constant and 0.61 as multiplier.
	const double CONSTANT = 331.3;
	const double MULTIPLIER = 0.61;
	
	int startTemperature, endTemperature; 
	double velocity;
	cout << "Welcome, this program will show you velocity of sound at a temperature range provided by you!" << endl;
	cout << "Enter starting point of temperature (in degree Celsius): ";
	cin >> startTemperature;
	cout << "Enter the end point of temperature (in degree Celsius): ";
	cin >> endTemperature;
	
	if (startTemperature < endTemperature)
	{
		//We take startTemperature as initator and endTemperature as limit.
		//Then print speed at each temperature.
		for (startTemperature; startTemperature <= endTemperature; startTemperature++)
		{
			velocity = CONSTANT + (MULTIPLIER * startTemperature);
			cout << "At " << startTemperature << " degrees Celsius the velocity of sound is " << velocity << "m/s" << endl;
		}
	}
	else if (startTemperature > endTemperature)
	{
		for (startTemperature; startTemperature >= endTemperature; startTemperature--)
		{
			velocity = CONSTANT + (MULTIPLIER * startTemperature);
			cout << "At " << startTemperature << " degrees Celsius the velocity of sound is " << velocity << "m/s" << endl;
		}
	}
	else 
	{
		velocity = CONSTANT + (MULTIPLIER * startTemperature);
		cout << "At " << startTemperature << " degrees Celsius the velocity of sound is " << velocity << "m/s" << endl;
	}
	
	return 0;
}

















