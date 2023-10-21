#include <iostream>

using namespace std;

void square();

void right_triangle_1();

void inverted_right_triangle_1();

void right_triangle_2();

void inverted_right_triangle_2();

void loop(bool& lever);

int main()
{
	bool lever{};	
	while (!lever)
	{
		square();
		right_triangle_1();
		inverted_right_triangle_1();
		right_triangle_2();
		inverted_right_triangle_2();

		loop(lever);
	}
	return 0;
}

void square()
{
	int size {};
	cout << "Enter size for a Square: ";
	cin >> size;
	cout << '\n';

	for (int i=0; i < size; i++)
	{
		for (int j=0; j < size; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}
	cout << '\n';
}

void right_triangle_1()
{
	int size {};
	cout << "Enter size for a left-inclined Right Triangle: ";
	cin >> size;
	cout << '\n';

	for (int i=size; i > 0; i--)
	{
		for (int j=i-1; j < size; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}
	cout << '\n';
}

void inverted_right_triangle_1()
{
	int size {};
	cout << "Enter size for a left-inclined Inverted Right Triangle: ";
	cin >> size;
	cout << '\n';

	for (int i=0; i < size; i++)
	{
		for (int j=size-i; j > 0; j--)
		{
			cout << "*";
		}
		cout << '\n';
	}
	cout << '\n';
}

void right_triangle_2()
{
	int size {};
	cout << "Enter size for a right-inclined Right Triangle: ";
	cin >> size;
	cout << '\n';

	int l{size};
	for (int i=0; i < size; i++)
	{
		for (int j=size-i; j > 0; j--)
		{
			cout << " ";
		}
		for (int k=l-1; k < size; k++)
		{
			cout << "*";
		}
		cout << '\n';
		l--;
	}
	cout << '\n';
}

void inverted_right_triangle_2()
{
	int size {};
	cout << "Enter size for a right-inclined Inverted Right Triangle: ";
	cin >> size;
	cout << '\n';

	int l{0};
	for (int i=size; i > 0; i--)
	{
		for (int j=i-1; j < size; j++)
		{
			cout << " ";
		}
		for (int k=size-l; k > 0; k--)
		{
			cout << "*";
		}
		l++;
		cout << '\n';

	}
	cout << '\n';
}

void loop(bool& lever)
{
	while (true)
	{
		char input {};
		cout << "Run program again? (Y/N): ";
		cin >> input;
		if (input == 'Y' || input == 'y')
		{
			lever = false;
			break;
		}
		else if (input == 'N' || input == 'n')
		{
			lever = true;
			break;
		}
		else 
		{
			cout << "Wrong input!\n";
		}
	}
}