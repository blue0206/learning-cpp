//Workers at a particular company have won a 7.6% pay increase retroactive for 6 months.
//Write a program that takes an employee’s previous annual salary as input, and outputs the
//amount of retroactive pay due the employee, the new annual salary, and the new monthly
//salary. Use a variable declaration with the modifier const to express the pay increase. Your
//program should allow the calculation to be repeated as often as the user wishes.
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char ask;
	do
	{
		const double PAY_INCREASE = 0.76;
		double previousAnnualSalary, newAnnualSalary, payDue, newMonthlySalary;
		
		cout << "Enter previous annual salary: ";
		cin >> previousAnnualSalary;
		
		newAnnualSalary = (previousAnnualSalary * PAY_INCREASE) + previousAnnualSalary;
		newMonthlySalary = newAnnualSalary / 12;
		payDue = previousAnnualSalary / 6;
		
		cout << "The retroactive pay due is $" << payDue << ".\n";
		cout << "The new annual salary is $" << newAnnualSalary << ".\n"; 
		cout << "The new monthly salary is $" << newMonthlySalary << endl;
		
		cout << "\n\n\n\n\n";
		
		cout << "Enter 'Y' to calculate again. Otherwise enter any other key to exit.";
		cin >> ask;
	} while (ask == 'Y' || ask == 'y');
	
	return 0;
}