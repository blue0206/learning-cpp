//Coded by Aayush Rai on 27 September 2022. 
//Takes wholesale price and shelf time as inputs from user.
//Displays retail price of an item according to the pricing policy of store.

#include <iostream>

const double LOW_MARKUP = 0.05;  
//5% rate
const double HIGH_MARKUP = 0.10; 
//10% rate
const int THRESHOLD = 7; 
//Use high markup if not expected to sell in 7 days or less.

void newLine();
//Enters a blank line in output for easy read.
void introduction();
//Welcome message. Purpose of program.
void input(double& price, int& turnover);
//Takes input from the user.
//Price is the wholesale price of the item and 
//turnover is expected no. of days until the sale of item.
double retailPrice(double price, int turnover);
//Takes in wholesale price of item and turnover, and
//Returns the retail price of the item.
void output(double price, int turnover, double retailPrice);
//The values are written to the screen.
void repeatCalculation(bool& ans);
//Ask user to calculate again.

int main()
{
	introduction();
	bool answer;
	do
	{
		double wholesalePrice;
		int shelfTime;
		input(wholesalePrice, shelfTime);
		output(wholesalePrice, shelfTime, retailPrice(wholesalePrice, shelfTime));
		repeatCalculation(answer);
	}
	while(answer);
	return 1;
}

void introduction()
{
	using namespace std;
	cout << "Welcome! This program determines the retail price of an item "; 
	cout << "at a supermarket.\n";
	newLine();
}

void input(double& price, int& turnover)
{
	using namespace std;
	cout << "Enter the wholesale price of the item: $";
	cin >> price;
	cout << "Enter the expected number of days until the item is sold: ";
	cin >> turnover;
	newLine();
}

double retailPrice(double price, int turnover)
{
	if (turnover <= THRESHOLD)
	{
		return ((price * LOW_MARKUP) + price);
	}
	else
	{
		return ((price * HIGH_MARKUP) + price);
	}
}

void output(double price, int turnover, double retailPrice)
{
	using namespace std;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "The wholesale price of the item is: $" << price;
	newLine();
	cout << "\nThe expected number of days until the item is sold is: ";
	cout << turnover << " days.\n";
	newLine();
	cout << "Therefore, the retail price of the item";
	cout << " is: $" << retailPrice << endl;
	newLine();
}

void repeatCalculation(bool& ans)
{
	using namespace std;
	char prompt;
	cout << "Repeat calculation? (Y/N) : ";
	cin >> prompt;
	if (prompt == 'Y' || prompt == 'y')
	{
		ans = true;
	}
	else 
	{
		ans = false;
	}
	newLine();
}

void newLine()
{
	using namespace std;
	cout << endl;
}