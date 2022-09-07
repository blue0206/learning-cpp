#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	//The task is to convert 'miles per hour' into 'minutes and seconds per mile.'
	//Create double-types named mph (miles per hour), hpm (hours per mile), mpm, seconds (miles per minutes and seconds).
	double mph, hpm, mpm, seconds;
	cout << "Enter the speed in mph: ";
	cin >> mph;
	
	hpm = 1 / mph;
	mpm = hpm * 60;
	//Calculate the seconds FROM mpm by subtracting the 'int' version of mpm from the total mpm. The multiplier 60 marks conversion into seconds.
	seconds = (mpm * 60) - ((static_cast<int>(mpm)) * 60);
	
	//Convert mpm to int
	mpm = static_cast<int>(mpm);
	
	
	cout << mph << " miles per hour is ";
	cout << mpm << " minutes and ";
	cout << seconds << " seconds per mile." << endl;
	
	return 0;
}