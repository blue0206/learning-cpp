//Coded by Aayush Rai on 28 September 2022. 
//This program is an exercise given in "Problem Solving with C++."
//The program takes input from user and carries out conversions.

#include <iostream>
#include <cmath>

const double M_IN_FOOT = 0.3048;  	//Meters in 1 foot.
const double CM_IN_M = 100;       	//Centimeters in 1 meter.
const double INCHES_IN_FOOT = 12; 	//Inches in 1 foot.
const double POUNDS_IN_KG = 2.2046; //Pounds in 1 Kg.
const double G_IN_KG = 1000;		//Grams in 1 Kg.
const double OUNCES_IN_POUND = 16;	//Ounces in 1 Pound.

void blank();
//Adds blank line.
void welcome();
//Prints introduction.
void ask(int& choice);
//Ask user to convert length or weight.
//Input '1' for former and '2' for latter.
void askLength(int& prompt);
//Ask user for feet and inches to meter and cm conversion
//or meter and cm to feet and inches conversion.
//Input '1' for former and '2' for latter.
void askWeight(int& prompt);
//Ask user for pounds and ounces to kg and gram conversion
//or kg and gram to pounds and ounces conversion.
//Input '1' for former and '2' for latter.
void inputLength1(double& feet, double& inch);
//Takes input for feet and inches.
void inputLength2(double& meter, double& cm);
//Takes input for meter and cm.
double convert1M(double feet, double inch);
//Converts feet and inches to meters.
double convert1CM(double meter);
//Extracts centimeters from meters if meter is greater than 1.
double convert2F(double meter, double cm);
//Converts meter and cm to feet.
double convert2I(double feet);
//Extracts inches from feet if feet is greater than 1.
void outputLength(int feet, int inch, int meter, int centimeter, int response);
//Prints the conversion on the screen.
void inputWeight1(double& pound, double& ounce);
//Takes input for pounds and ounces.
void inputWeight2(double& kilogram, double& gram);
//Takes input for kg and grams.
double convert1KG(double pound, double ounce);
//Converts pounds and ounces to kg.
double convert1G(double kilogram);
//Extracts grams from kg if kg is greater than 1.
double convert2P(double kilogram, double gram);
//Converts kg and grams to pounds.
double convert2Ounce(double pound);
//Extracts ounces from pounds when pound is greater than 1.
void outputWeight(int pound, int ounce, int kilogram, int gram, int response);
//Prints the conversion on the screen.
void noAns();
//Asks user for right input when asking for type of conversion.
//Activates when user inputs wrong.
void repeat(bool& ans);
//Asks to repeat calculation by 'Y' for YES and 'N' 
//or any other character for NO.

int main()
{
	welcome();
	bool ans;
	do
	{		
		int userChoice;
		ask(userChoice);
		if (userChoice == 1)
		{
			double centimeter, meter, inch, feet;
			int response;
			askLength(response);
			if (response == 1)
			{
				inputLength1(feet, inch);
				blank();
				meter = convert1M(feet, inch);
				centimeter = convert1CM(meter);
				outputLength(feet, inch, meter, centimeter, response);
				blank();
			}
			else if (response == 2)
			{
				inputLength2(meter, centimeter);
				blank();
				feet = convert2F(meter, centimeter);
				inch = convert2I(feet);
				outputLength(feet, inch, meter, centimeter, response);
				blank();
			}
			else
			{
				noAns();
			}
		}
		else if (userChoice == 2)
		{
			double gram, kilogram, ounce, pound;
			int response;
			askWeight(response);
			if (response == 1)
			{
				inputWeight1(pound, ounce);
				kilogram = convert1KG(pound, ounce);
				gram = convert1G(kilogram);
				outputWeight(pound, ounce, kilogram, gram, response);
			}
			else if (response == 2)
			{
				inputWeight2(kilogram, gram);
				pound = convert2P(kilogram, gram);
				ounce = convert2Ounce(pound);
				outputWeight(pound, ounce, kilogram, gram, response);
			}
			else
			{
				noAns();
			}
		}
		else
		{
			noAns();
		}
		
		repeat(ans);
	}
	while (ans);
	return 1;
}

void welcome()
{
	using namespace std;
	cout << "Welcome! You can use this program for length conversion and weight conversion.\n";
	cout << "The length conversion is between feet-inches and meter-centimeter.\n";
	cout << "The weight conversion is between pound-ounces and kilogram-grams.\n";
	cout << "Just follow the instructions and you can use the program as many times as you want!\n";
	blank();
}

void ask(int& choice)
{
	using namespace std;
	cout << "Enter '1' for Length conversion.\n";
	cout << "Enter '2' for Weight conversion.\n";
	cin >> choice;
	blank();
}

void askLength(int& prompt)
{
	using namespace std;
	cout << "Enter '1' to convert from feet and inches to meters and centimeters.\n";
	cout << "Enter '2' to convert from meters and centimeters to feet and inches.\n";
	cin >> prompt;
	blank();
}

void askWeight(int& prompt)
{
	using namespace std;
	cout << "Enter '1' to convert from pounds and ounces to kilograms and grams.\n";
	cout << "Enter '2' to convert from kilograms and grams to pounds and ounces.\n";
	cin >> prompt;
	blank();
}

void inputLength1(double& feet, double& inch)
{
	using namespace std;
	cout << "Enter feet: ";
	cin >> feet;
	cout << "Enter inches: ";
	cin >> inch;
}

void inputLength2(double& meter, double& cm)
{
	using namespace std;
	cout << "Enter meters: ";
	cin >> meter;
	cout << "Enter centimeters: ";
	cin >> cm;
}

double convert1M(double feet, double inch)
{
	inch = inch / INCHES_IN_FOOT;
	feet += inch;
	return (feet * M_IN_FOOT);
}

double convert1CM(double meter)
{
	double tempCM = (floor(meter) * CM_IN_M);
	return ((meter * CM_IN_M) - tempCM);
}

double convert2F(double meter, double cm)
{
	cm = cm / CM_IN_M;
	meter += cm;
	return (meter / M_IN_FOOT);
}

double convert2I(double feet)
{
	double tempI = (floor(feet) * INCHES_IN_FOOT);
	return ((feet * INCHES_IN_FOOT) - tempI);
}

void outputLength(int feet, int inch, int meter, int centimeter, int response)
{
	using namespace std;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (response == 1)
	{
		cout << feet << " feet and " << inch << " inches is: ";
		cout << meter << " meters and " << centimeter << " centimeters.\n";
	}
	else
	{
		cout << meter << " meters and " << centimeter << " centimeters is: ";
		cout << feet << " feet and " << inch << " inches.\n";
	}
}

void inputWeight1(double& pound, double& ounce)
{
	using namespace std;
	cout << "Enter pounds: ";
	cin >> pound;
	cout << "Enter ounces: ";
	cin >> ounce;
}

void inputWeight2(double& kilogram, double& gram)
{
	using namespace std;
	cout << "Enter kilograms: ";
	cin >> kilogram;
	cout << "Enter grams: ";
	cin >> gram;
}

double convert1KG(double pound, double ounce)
{
	ounce = ounce / OUNCES_IN_POUND;
	pound += ounce;
	return (pound / POUNDS_IN_KG);
}

double convert1G(double kilogram)
{
	double temp = (floor(kilogram) * G_IN_KG);
	return ((kilogram * G_IN_KG) - temp);
}

double convert2P(double kilogram, double gram)
{
	gram = gram / G_IN_KG;
	kilogram += gram;
	return (kilogram * POUNDS_IN_KG);
}

double convert2Ounce(double pound)
{
	double temp = (floor(pound) * OUNCES_IN_POUND);
	return ((pound * OUNCES_IN_POUND) - temp);
}

void outputWeight(int pound, int ounce, int kilogram, int gram, int response)
{
	using namespace std;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (response == 1)
	{
		cout << pound << " pounds and " << ounce << " ounces is: ";
		cout << kilogram << " kilograms and " << gram << " grams.\n";
	}
	else
	{
		cout << kilogram << " kilograms and " << gram << " grams is: ";
		cout << pound << " pounds and " << ounce << " ounces.\n";
	}
}

void noAns()
{
	using namespace std;
	cout << "You entered wrong. Please enter '1' or '2'!\n";
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