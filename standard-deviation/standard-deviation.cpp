//Coded by Aayush Rai on 28 September 2022. 
//This program takes in 4 scores and outputs their
//average and standard deviation.

#include <iostream>
#include <cmath>

void blank();
//Adds a new blank line.
void welcome();
//Prints introduction.
void input(double& s1, double& s2, double& s3, double& s4);
//Takes input for scores.
double avg(double s1, double s2, double s3, double s4);
//Calculates the average of all scores.
double stdDeviation(double avg);
//Calculates the standard deviation of scores.
void output(double avg, double deviation);
//Prints values to the screen.
void repeat(bool& ans);
//Asks to repeat calculation.

int main()
{
	welcome();
	bool ans;
	do
	{
		double score1, score2, score3, score4;
		input(score1, score2, score3, score4);
		
		double average = avg(score1, score2, score3, score4);
		double deviation = stdDeviation(avg(score1, score2, score3, score4));
		
		output(average, deviation);
		repeat(ans);
		blank();
	}
	while (ans);
	return 1;
}

void welcome()
{
	using namespace std;
	cout << "Welcome! This program takes in four scores and\n";
	cout << "prints out their average and standard deviation.\n";
	blank();
}

void input(double& s1, double& s2, double& s3, double& s4)
{
	using namespace std;
	cout << "Enter first score: ";
	cin >> s1;
	cout << "Enter second score: ";
	cin >> s2;
	cout << "Enter third score: ";
	cin >> s3;
	cout << "Enter fourth score: ";
	cin >> s4;
	blank();
}

double avg(double s1, double s2, double s3, double s4)
{
	return ((s1 + s2 + s3 + s4) / 4);
}

double stdDeviation(double avg)
{
	return (sqrt(avg));
}

void output(double avg, double deviation)
{
	using namespace std;
	cout << "The average of scores is: " << avg;
	cout << "\nThe standard deviation is: " << deviation<< endl;
}

void repeat(bool& ans)
{
	using namespace std;
	char prompt;
	cout << "Calculate again? (Y/N) : ";
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