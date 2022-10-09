//Coded by Aayush Rai on 7 October 2022. 
//This is an exercise in the book 'Problem Solving with C++.'
//We take input from a file with a list of numbers with each on different line
//and output the greatest and the smallest of those numbers in an output file.

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void sort(ifstream& fin, ofstream& fout);
//Takes input from input file and writes the greatest and smallest number to 
//the output file.

int main()
{
	ifstream inStream;
	ofstream outStream;
	
	inStream.open("infile.dat");
	if (inStream.fail())
	{
		cout << "Input file opening failed.\n";
		exit (1);
	}
	
	outStream.open("outfile.dat");
	if (outStream.fail())
	{
		cout << "Output file opening failed.\n";
		exit (1);
	}
	
	sort(inStream, outStream);
	
	inStream.close();
	outStream.close();
	
	cout << "End of program.\n";
}

void sort(ifstream& fin, ofstream& fout)
{
	int input, greatest, smallest;
	fin >> input;
	greatest = input;
	
	fin >> input;
	smallest = input;
	
	while (! fin.eof())
	{
		fin >> input;
		if (input > greatest)
		{
			greatest = input;
		}
		else if (input < smallest)
		{
			smallest = input;
		}
	}
	
	fout << "Greatest number is: " << greatest << endl;
	fout << "Smallest number is: " << smallest;
}



