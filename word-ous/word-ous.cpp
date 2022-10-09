//Coded by Aayush Rai on 9 October 2022. 
//This is a programming project in the book "Problem Solving with C++."
//We have a file named 'words.txt' with 87,314 words. 
//This program finds all the words ending with 'dous' in 'words.txt' 
//and outputs them in  the output file 'output.txt' and on screen.

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

void wordFinder(istream& fin, istream& ins, ostream& fout);
//Takes two input file streams of same file, one to search by string
//and the other to search by character. 
//Takes one output file stream to output the results.

int main()
{
	ifstream fin;
	ifstream ins;
	ofstream fout;

	fin.open("words.txt");
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit (1);
	}
	ins.open("words.txt");
	if (ins.fail())
	{
		cout << "Input file opening failed.\n";
		exit (1);
	}
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Output file opening failed.\n";
		exit (1);
	}
	
	fout << "The words ending with 'dous' are:";
	cout << "The words wnding with 'dous' are:";
	
	wordFinder(fin, ins, fout);
	
	fin.close();
	ins.close();
	fout.close();
	
	cout << "\nEnd of program.\n";
	return 0;
}

void wordFinder(istream& fin, istream& ins, ostream& fout)
{
	string input;
	char next;
	
	ins >> input;			//Searches by string.
	fin.get(next);			//Searches by character.
	
	while (!fin.eof())
	{						//If the charcter is 'd' then we get another character from input and moving
		if (next == 'd')	//moving on with conditionals, the words ending with 'dous' are output.
		{					//Else the conditional breaks and we keep getting charcters from input till all
			fin.get(next);	 //conditions are fulfilled.
			
			if (next == 'o')       							
			{
				fin.get(next);
				
				if (next == 'u')						
				{
					fin.get(next);
					
					if (next == 's')					
					{
						fin.get(next);					
						
						if (next == '\n')				
						{								
							fout << endl << input;		//String containing 'dous' are output.	
							cout << endl << input;
						}
					}
				}
			}
		}
		
		if (next == '\n')
		{
			ins >> input;		//Moves on to next word at line break to be synchronised with character search.
		}
		
		fin.get(next);
	}
}