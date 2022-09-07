#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() 
{
	//Create string variables and an int variable.
	string instructorName, userName, food;
	string adjective, color, animal;
    int	num;
	
	cout << "Enter your instructor's name: ";
	cin >> instructorName;
	cout << "Enter your name: ";
	cin >> userName;
	cout << "Enter the name of a food: ";
	cin >> food;
	cout << "Enter an adjective: ";
	cin >> adjective;
	cout << "Enter a color name: ";
	cin >> color;
	cout << "Enter the name of an animal: ";
	cin >> animal;
	
	//Prompt user to input a number between 100 and 120 using do-while loop.
	do
	{
		cout << "Enter a number between 100 and 120: ";
		cin >> num;
	} while (num <= 100 || num >= 120);
	
	cout << endl;
		
	cout << "Dear " << instructorName << "," << endl << endl;
	cout << "I am sorry that I am unable to turn in my homework at this time. "
	     << "First, I ate a rotten " << food << ", "
		 << "which made me turn " << color << " and extremely ill. "
		 << "I came down with a fever of " << num << ". "
		 << "Next, my " << adjective << " pet " << animal
		 << " must have smelled the remains of the " << food
		 << " on my homework, because he ate it. I am currently rewriting my "
		 << "home work and hope you will accept it late." << endl << endl;
	cout << "Sincerely," << endl;
	cout << userName << endl;
	
	return 0;
}














