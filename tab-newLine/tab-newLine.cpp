#include <iostream>

using namespace std;

int main()
{	
	double one = 1.000, two = 1.414, three = 1.732,
		   four = 2.000, five = 2.236;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	
	cout << "N\t" << "Square Root\n"
		 << "1\t" << one << endl
		 << "2\t" << two << endl
		 << "3\t" << three << endl
		 << "4\t" << four << endl
		 << "5\t" << five << endl;
	
	return 0;
}