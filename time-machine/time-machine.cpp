//Coded by Aayush Rai on 23 September 2022. 
//This is a programming project from the book, "Problem Solving with C++."
//The program assumes you have a time machine which can travel to a
//maximum of 24 hours into the future. The machine takes input in minutes.
//You input start time and future time in 12-hour format and the program
//outputs the time-difference in minutes to be inserted in time-machine.

#include <iostream>
#include <string>

using namespace std;

double minutes(int hours, int minutes, bool isAM);
//Calculates the start time and future time in minutes
//after converting into 24-hour time format.
double computeDifference(double startTime, double futureTime);
//Calculates the time difference in minutes.

int main()
{
	char prompt;
	do
	{
		int startHours, startMinutes,
		futureHours, futureMinutes;
		char startAP, futureAP;
		bool isAM;
		
		cout << "Enter start time in hours (12-hour format): ";
		cin >> startHours;
		cout << "Enter the minutes in start time: ";
		cin >> startMinutes; 
		cout << "Enter 'A' for AM or 'P' for PM: ";
		cin >> startAP;
		cout << endl;
		
		if (startAP == 'A' || startAP == 'a')
		{
			isAM = true;
		}
		else 
		{
			isAM = false;
		}
		
		double startTime = minutes(startHours, startMinutes, isAM);
		
		cout << "Enter future time in hours (12-hour format): ";
		cin >> futureHours;
		cout << "Enter the minutes in future time: ";
		cin >> futureMinutes; 
		cout << "Enter 'A' for AM or 'P' for PM: ";
		cin >> futureAP;
		cout << endl;
		
		if (futureAP == 'A' || futureAP == 'a')
		{
			isAM = true;
		}
		else
		{
			isAM = false;
		}
		
		double futureTime = minutes(futureHours, futureMinutes, isAM);
		
		double timeDifference = computeDifference(startTime, futureTime);
		string alert = "The time difference is above 24 hours. OUT OF LIMIT!";
		
		if (timeDifference <= 1)
		{
			cout << alert << endl;
		}	
		else
		{
			cout << "The start time in minutes is:\n" << startTime;
			cout << " minutes.\n";
			cout << "The future time in minutes is:\n";
			cout << futureTime << " minutes.\n";
			cout << "Therefore, the time difference is:\n";
			cout << timeDifference << " minutes.\n";
		}
		
		cout << "Enter 'Y' to calculate again: ";
		cin >> prompt;
	}
	while(prompt == 'Y' || prompt == 'y');	
	
	return 1;
	
}

double minutes(int hours, int minutes, bool isAM)
{
	if ((hours == 12) && (isAM == true))
	{
		hours += 12;
	}
	else if ((hours == 12) && (isAM == false))
	{
		hours = hours;
	}
	else if (isAM == false)
	{
		hours += 12;			//Conversion to 24-hour format.
	}
	hours *= 60;
	return (hours + minutes);
}

double computeDifference(double startTime, double futureTime)
{	
	if (startTime > futureTime)
	{
		double difference = 1440 + futureTime;
		difference = difference - startTime;
		if (difference <= 1440)
		{
			return (difference);
		}
		else 
		{
			return 0;
		}
	}
	else if (startTime < futureTime)
	{
		return (futureTime - startTime);
	}
	else
	{
		return 0;
	}
}
