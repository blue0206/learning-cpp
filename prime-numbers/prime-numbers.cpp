#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	//This program finds all the prime numbers between 1 and 100.
	int prime;
	for (int num = 2; num <=100; num++)
	{
		for (int div = 2; div < num; div++)
		{
			prime = num % div;
			if (prime == 0)
			{
				break;    //Break the loop when the number is divisible.
			}
		}
		if (prime != 0)
		{
			cout << num << " is a Prime Number.\n";
		}
	}
	return 0;
}