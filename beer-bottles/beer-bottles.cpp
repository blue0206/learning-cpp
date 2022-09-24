//Coded by Aayush Rai on 23 September 2022. This is a programming project given
//in book, "Problem Solving with C++." We print the lyrics for the song
//"Ninety-Nine Bottles of Beer on the Wall." The program takes input from user
//and prints the number of bottles in English all the way down to 0.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

string extractOnes(int num);
//Extracts the ones digit AS WELL AS few other numbers
//and returns the number in English as a string.
string extractTens(int num);
//Extracts the tens digit of the number and returns in
//English as a string.

int main()
{
	int num;
	do
	{
		cout << "Enter number of bottles (from 0 to 99): ";
		cin >> num;
	}
	while(num < 0 || num > 99);
	
	while(num > 0)
	{
		cout << extractTens(num) << extractOnes(num);
		cout << " bottles of beer on the wall,\n";
		cout << extractTens(num) << extractOnes(num);
		cout << " bottles of beer.\n" << endl;
		cout << "Take one down, pass it around,\n";
		num--;
	}
	
	cout << "Zero bottles of beer on the wall.\n" << endl;
	cout << "PARTY'S OVER :(\n" << endl;
	
	return 0;
}

string extractOnes(int num)
{
	if (num == 1)
	{
		return "One";
	}
	else if (num == 2)
	{
		return "Two";
	}
	else if (num == 3)
	{
		return "Three";
	}
	else if (num == 4)
	{
		return "Four";
	}
	else if (num == 5)
	{
		return "Five";
	}
	else if (num == 6)
	{
		return "Six";
	}
	else if (num == 7)
	{
		return "Seven";
	}
	else if (num == 8)
	{
		return "Eight";
	}
	else if (num == 9)
	{
		return "Nine";
	}
	else if (num == 10)
	{
		return "Ten";
	}
	else if (num == 11)
	{
		return "Eleven";
	}
	else if (num == 12)
	{
		return "Twelve";
	}
	else if (num == 13)
	{
		return "Thirteen";
	}
	else if (num == 14)
	{
		return "Fourteen";
	}
	else if (num == 15)
	{
		return "Fifteen";
	}
	else if (num == 16)
	{
		return "Sixteen";
	}
	else if (num == 17)
	{
		return "Seventeen";
	}
	else if (num == 18)
	{
		return "Eighteen";
	}
	else if (num == 19)
	{
		return "Nineteen";
	}
	else if ((num % 10) == 1)
	{
		return "-One";
	}
	else if ((num % 10) == 2)
	{
		return "-Two";
	}
	else if ((num % 10) == 3)
	{
		return "-Three";
	}
	else if ((num % 10) == 4)
	{
		return "-Four";
	}
	else if ((num % 10) == 5)
	{
		return "-Five";
	}
	else if ((num % 10) == 6)
	{
		return "-Six";
	}
	else if ((num % 10) == 7)
	{
		return "-Seven";
	}
	else if ((num % 10) == 8)
	{
		return "-Eight";
	}
	else if ((num % 10) == 9)
	{
		return "-Nine";
	}
	else 
	{
		return "";
	}
}

string extractTens(int num)
{
	if ((num / 10) == 2)
	{
		return "Twenty";
	}
	else if ((num / 10) == 3)
	{
		return "Thirty";
	}
	else if ((num / 10) == 4)
	{
		return "Fourty";
	}
	else if ((num / 10) == 5)
	{
		return "Fifty";
	}
	else if ((num / 10) == 6)
	{
		return "Sixty";
	}
	else if ((num / 10) == 7)
	{
		return "Seventy";
	}
	else if ((num / 10) == 8)
	{
		return "Eighty";
	}
	else if ((num / 10) == 9)
	{
		return "Ninety";
	}
	else 
	{
		return "";
	}
}







