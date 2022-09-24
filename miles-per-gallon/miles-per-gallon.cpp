//Coded by Aayush Rai. Practice program given in book "Problem Solving with C++"
//The program takes input of liters of fuel consumed and miles travelled and 
//produces output in miles travelled per gallon.

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const double GALLONS_PER_LITER = 0.264179;

double milesPerGallon(double gasolineLiters, double milesTravelled);
//Calculates the miles travelled per gallon by taking in arguments for liters of
//fuel consumed as well as miles travelled by the vehicle. 

int main()
{
	cout << "Welcome! This program takes in arguments for the amount of fuel\n";
	cout << "consumed in liters as well as miles travelled, and produces output\n"; 
	cout << "in miles travelled per gallon!\n";
	
	char prompt;
	
	do
	{
		double gasolineLiters, 
		   milesTravelled;
	
		cout << "Input the liters of gasoline consumed: ";
		cin >> gasolineLiters;
		cout << "Input the miles travelled per liter: ";
		cin >> milesTravelled;
		
		cout << "The vehicle travelled " << milesPerGallon(gasolineLiters, milesTravelled);
		cout << " miles per gallon.\n";
		
		cout << "Press 'Y' to calculate again: ";
		cin >> prompt;
	}
	while(prompt == 'Y' || prompt == 'y');
	
	return 1;
}

double milesPerGallon(double gasolineLiters, double milesTravelled)
{
	double gasolineGallons = gasolineLiters * GALLONS_PER_LITER;
	
	return (milesTravelled / gasolineGallons);
}