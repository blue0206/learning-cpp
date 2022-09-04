# include <iostream>

using namespace std;

int main()
{
	int ast = 49;
	int c = 3;
	int s = 4;
	
	//Line 1
	for (int i = 0; i < ast; i++)
	{
		cout << "*";
	}
	cout << "\n";
	
	//Line 2, blank
	cout << "\n";
	
	//Line 3	
	cout << "       ";	
	for (int i = 0; i < c; i++)
	{
		cout << "C "; 
	}
	cout << "           ";	
	for (int i = 0; i < s; i++)
	{
		cout << "S ";
	}
	cout << "        !!\n";
	
	//Line 4
	cout << "     C";
	cout << "       C";
	cout << "        S";
	cout << "         S";
	cout << "       !!\n";
	
	//Line 5
	cout << "    C";
	cout << "                S";
	cout << "                  !!\n";
	
	//Line 6
	cout << "   C";
	cout << "                  S";
	cout << "                 !!\n";
	
	//Line 7
	cout << "   C";
	cout << "                    ";
	for (int i = 0; i < s; i++)
	{
		cout << "S ";
	}
	cout << "        !!\n";
	
	//Line 8
	cout << "   C";
	cout << "                            S";
	cout << "       !!\n";
	
	//Line 9
	cout << "    C";
	cout << "                            S";
	cout << "      !!\n";
	
	//Line 10
	cout << "     C";
	cout << "       C";
	cout << "        S";
	cout << "         S\n";
	
	//Line 11
	cout << "       ";	
	for (int i = 0; i < c; i++)
	{
		cout << "C "; 
	}
	cout << "           ";	
	for (int i = 0; i < s; i++)
	{
		cout << "S ";
	}
	cout << "        00\n";
	
	//Line 12
	cout << "\n";
	
	//Line 13
	for (int i = 0; i < ast; i++)
	{
		cout << "*";
	}
	cout << "\n";

	//Line 14
	cout << "    Computer Science is Cool Stuff!!!\n";
	
	return 0;
}






