#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	{
		int size;
		do
		{
			cout << "Enter size: ";
			cin >> size;
		}
		while (size < 1 || size > 8);
		
		for (int i = size - 1; i >= 0 && i < size; i--)
		{
			for (int j = 0; j < size; j++)
			{
				if (j == i || j > i)
				{
					cout << "#";
				}
				else 
				{
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}