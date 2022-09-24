#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


double pricePerSquareInch(double diameter, double price);
//Calculates the price per square inch of each pizza.
//Converts diameter to radius, then calculates the area.
//Divides price by area and returns the output.


int main()
{
	cout << "Welcome! This program determines which pizza is ";
	cout << "the best buy!" << endl;
	
	double price1, price2, diameter1, diameter2;
	cout << "Enter the diameter of the first pizza: ";
	cin >> diameter1;
	cout << "Enter the price of the first pizza: $";
	cin >> price1;
	cout << "Enter the diameter of the second pizza: ";
	cin >> diameter2;
	cout << "Enter the price of the second pizza: $";
	cin >> price2;
	cout << endl;
	
	double pricePerInch1 = pricePerSquareInch(diameter1, price1),
		   pricePerInch2 = pricePerSquareInch(diameter2, price2);
	
	cout << "Price per square inch of first pizza is $" << pricePerInch1 << endl;
	cout << endl;
	cout << "Price per square inch of second pizza is $" << pricePerInch2 << endl;
	cout << endl;
	
	if (pricePerInch1 < pricePerInch2)
	{
		cout << "The first pizza is the better buy." << endl;
	}
	else if (pricePerInch1 > pricePerInch2)
	{
		cout << "The second pizza is the better buy." << endl;
	}
	else
	{
		if (diameter1 > diameter2)
		{
			cout << "The first pizza is the better buy." << endl;
		}
		else if (diameter1 < diameter2)
		{
			cout << "The second pizza is the better buy." << endl;
		}
		else
		{
			cout << "The pizzas are the same!" << endl;
		}
	}
	cout << endl;
	
	return 0;
}

double pricePerSquareInch(double diameter, double price)
{
	double radius = diameter / static_cast<double>(2);
	double PI = static_cast<double>(22) / static_cast<double>(7);
	double area = PI * radius * radius;
	return price / area;
}

