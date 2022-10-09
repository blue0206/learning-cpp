//Coded by Aayush Rai on 29 Spetember 2022.
//The program takes input for current time and waiting time
//and outputs the time after waiting. 
//This program is a project given in "Problem Solving with C++."
//The time format is 24h.

#include <iostream>
#include <cmath>

const double M_IN_H = 60; //Minutes in 1 hour.
const int H_IN_DAY = 24;  //Hours in 1 day.

void blank();
//Adds blank line for spacing.
void welcome();
//Prints introduction.
void inputCurrent(int& hours, int& min);
//Takes input for current time in hours and minutes.
//0 <= Hours <= 24 and 0 <= minutes <= 60.
void inputWaiting(int& hours, int& min);
//Takes input for waiting time in hours and minutes.
double minToHours(double hours, double min);
//Converts hours and minutes into decimal hours.
double finalTime(double current, double waiting);
//Converts decimal hours back to hours and minutes
//and returns final time after calculation.
void output(int hoursC, int minC, int hoursW, int minW, double finalTime);
//Prints output to the screen.
void repeat(bool& ans);
//Asks for calculating again.

int main()
{
	welcome();
	blank();
	bool ans;
	do
	{
		int hoursCurrent, minCurrent, hoursWaiting, minWaiting;
		
		inputCurrent(hoursCurrent, minCurrent);
		inputWaiting(hoursWaiting, minWaiting);
		
		double outputTime = finalTime((minToHours(hoursCurrent, minCurrent)), (minToHours(hoursWaiting, minWaiting)));
		//Final time takes in the decimal hour values using minToHours function for current and waiting time.
		
		output(hoursCurrent, minCurrent, hoursWaiting, minWaiting, outputTime);
		repeat(ans);
		blank();
	}
	while (ans);
	return 1;
}

void welcome()
{
	using namespace std;
	cout << "Welcome! This program takes input for current time and\n";
	cout << "waiting time, and outputs the future time!\n";
	cout << "Make sure to input time in 24 hour format.\n";
	cout << "You can use the program as many times as you wish.\n";
	cout << "P.S. There's also a hidden feature in this program, let's see if you can find it :)";
	blank();
}

void inputCurrent(int& hours, int& min)
{
	using namespace std;
	do
	{
		cout << "Enter current time in 24 hour format.\n";
		cout << "Hours: ";
		cin >> hours;
		cout << "Minutes: ";
		cin >> min;
	}
	while (hours > H_IN_DAY || min > M_IN_H || hours < 0 || min < 0);	
}

void inputWaiting(int& hours, int& min)
{
	using namespace std;
	cout << "Enter waiting time in 24 hour format.\n";
	cout << "Hours: ";
	cin >> hours;
	cout << "Minutes: ";
	cin >> min;
}

double minToHours(double hours, double min)
{
	if (min >= 1)
	{
		min = min / M_IN_H;
	}
	return (hours + min);
}

double finalTime(double current, double waiting)
{
	double total = current + waiting;
	if (total > 24)
	{
		for (int i = 0; total > H_IN_DAY; i++)
		{
			total = total - H_IN_DAY;				//Keep subtracting 24 from total till the time is in 24h format.
		}
		
		return total;
	}
	else
	{
		return total;
	}
}

void output(int hoursC, int minC, int hoursW, int minW, double finalTime)
{
	using namespace std;
	double finalHours, finalMin;
	finalHours = floor(finalTime);
	finalMin = ((finalTime - finalHours) * M_IN_H);
	
	cout << "The current time is " << hoursC << " hours and " << minC << " minutes.\n";
	cout << "The waiting time is " << hoursW << " hours and " << minW << " minutes.\n";
	blank();
	cout << "Therefore, after waiting, the time will be " << finalHours << " hours ";
	cout << "and " << finalMin << " minutes.\n";
	blank();
}

void repeat(bool& ans)
{
	using namespace std;
	char prompt;
	cout << "Test again? (Y/N) : ";
	cin >> prompt;
	if (prompt == 'Y' || prompt == 'y')
	{
		ans = true;
	}
	else 
	{
		ans = false;
	}
}

void blank()
{
	using namespace std;
	cout << endl;
}
