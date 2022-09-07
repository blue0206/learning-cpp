#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char prompt;
	do
	{
		//The values to be found.
		double faceValue, monthlyPayment, loanPeriod; 
		
		//Values to be input by user.
		double receiveAmount, rate, time;
		
		cout << "Enter the amount you want to receive: $";
		cin >> receiveAmount;
		cout << "Enter the interest rate you want (in percent): ";
		cin >> rate;
		cout << "Enter the duration of loan (in months): ";
		cin >> time;
		
		//Interest = Face Value * Rate
		//Interest * Loan Period = Face Value - Amount Received
		//Amount Received = Face Value - (Rate * Face Value * Loan Period)
		//Let rate * loanperiod be loan period interest
		
		rate /= 100;
		loanPeriod = time / 12;
		
		double loanPeriodInterest = rate * loanPeriod;
		loanPeriodInterest = 1 - loanPeriodInterest;
		faceValue *= loanPeriodInterest;
		faceValue = receiveAmount / loanPeriodInterest;
		
		monthlyPayment = faceValue / time;
		
		cout << "The face value you need for receiving $" << receiveAmount << " is $" << faceValue << endl;
		cout << "The monthly payment is $" << monthlyPayment << endl;
		
		cout << endl << endl;
		
		cout << "Enter 'Y' to calcualte again.\n" << "Enter any key to exit." << endl;
		cin >> prompt;
	} while (prompt == 'Y' || prompt == 'y');
	
	return 0;
}