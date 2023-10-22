//Coded by Aayush Rai on 22 October 2023.
//This program takes numeric values as input via file or keyboard
//and sorts them via Selection Sort.
//The output is printed either in file or on screen.

#include <iostream>
#include <fstream>
#include <cstdlib>

const int MAX_ARRAY_SIZE {101};
//Maximum array size.

void swap(int& num1, int& num2);
//Swaps value of two array indices.

void selection_sort(int a[], int size);
//Sorts the list using Selection Sort.

void ask_input_type(char& prompt);
//Asks user for file or keyboard input.

void file_input_array(int a[], int max_size, int& used_size);
//Takes numeric input from file. Appends them to array.

void screen_input_array(int a[], int max_size, int& used_size);
//Takes numeric input from user via keyboard. Appends to array.

void ask_output_type(char& prompt);
//Asks users for screen or file output.

void file_output_sorted_array(int a[], int size);
//Outputs sorted array to an output file.

void screen_output_sorted_array(int a[], int size);
//Outputs sorted array to screen.

void loop(bool& lever);
//Asks user whether to run program again.

int main()
{
    bool lever {true};
    while (lever)
    {
        //Initialize array with max size and used size.
        int arr[MAX_ARRAY_SIZE], used_size {};

        char input_type {}, output_type {};
        
        //INPUT
        {
            ask_input_type(input_type);
            if (input_type == 'F' || input_type == 'f')
            {
                //Takes input via file.
                file_input_array(arr, MAX_ARRAY_SIZE, used_size);
            }
            else if (input_type == 'K' || input_type == 'k')
            {
                //Takes input via keyboard.
                screen_input_array(arr, MAX_ARRAY_SIZE, used_size);
            }
        }

        selection_sort(arr, used_size);     //Implement Selection sort.

        //OUTPUT
        {
            ask_output_type(output_type);
            if (output_type == 'F' || output_type == 'f')
            {
                //Output in external file.
                file_output_sorted_array(arr, used_size);
            }
            else
            {
                //Output on screen.
                screen_output_sorted_array(arr, used_size);
            }
        }

        loop(lever);
    }
    return 0;
}

void swap(int& num1, int& num2)
{
    int temp {num1};
    num1 = num2;
    num2 = temp;
}

void selection_sort(int a[], int size)
{
    int range {}, smallest_num {}, smallest_index {};
    for (int i=0; i < size; i++)
    {
        //Set smallest_num to start index within range.
        smallest_num = a[range];
        for (int j=size - 1; j >= range; j--)
        {
            //Swaps smallest value into start index at the end of each pass.
            if ((j == range) && (smallest_num < a[range]))
            {
                //Swap the values of start index and the index having 
                //smallest value.
                swap(a[smallest_index], a[range]);
            }
            else if (smallest_num > a[j])
            {
                //Store the smallest value in smallest_num and the index number
                //of array carrying that value in smallest_index.
                smallest_num = a[j];
                //Store index for swapping in final pass of this loop.
                smallest_index = j;
            }
        }
        //Increment range by one after each pass of outer loop.
        range++;
    }
}

void ask_input_type(char& prompt)
{
    using namespace std;

    cout << "Enter 'f' for file input.\n"
         << "Enter 'k' to input manually via keyboard.\n"
         << "(Use file input for sorting negative numbers.)\n";
    cin >> prompt;    
}

void file_input_array(int a[], int max_size, int& used_size)
{
    using namespace std;

    ifstream fin;
    fin.open("unsorted.dat");
    if (fin.fail())
    {
        cout << "Input file opening failed!";
        exit (1);
    }

    int num {};
    //Take input till maximum array size is reached.
    while (used_size < max_size)
    {
        fin >> num;
        //In case file input < max size, break loop at end of file.
        if (fin.eof())
        {
            break;
        }
        //Store file input in a[used_size] where used_size starts at 0.
        a[used_size] = num;
        //Increment used_size with each pass for filling successive index.
        ++used_size;
    }

    fin.close();
}

void screen_input_array(int a[], int max_size, int& used_size)
{
    using namespace std;

    cout << "Enter numbers to be sorted one by one.\n"
         << "Enter a negative number to stop.\n";
    
    int num {};
    //Takes input till maximum array size is reached.
    while (used_size < max_size)
    {
        cout << "Enter Number: ";
        cin >> num;
        //Breaks loop to stop taking input in case the sentinel value 
        //which is negative number in this case, is entered.
        if (num < 0)
        {
            break;
        }
        a[used_size] = num;
        ++used_size;
    }
}

void ask_output_type(char& prompt)
{
    using namespace std;

    cout << "Enter 'f' for file output.\n"
         << "Enter 's' for screen output.\n";
    cin >> prompt;
}

void file_output_sorted_array(int a[], int size)
{
    using namespace std;

    ofstream fout;
    fout.open("sorted.dat");
    if (fout.fail())
    {
        cout << "Output file opening failed!";
        exit (1);
    }

    int index {};
    fout << "SORTED ARRAY:\n";
    while (index < size)
    {
        fout << a[index] << '\n';
        index++;
    }

    fout.close();
}

void screen_output_sorted_array(int a[], int size)
{
    using namespace std;

    cout << "\nSORTED ARRAY:\n";
    for (int index=0; index < size; index++)
    {
        cout << a[index] << '\n';
    }
}

void loop(bool& lever)
{
    using namespace std;

    char prompt {};
    while (true)
    {
        cout << "Run program again? (Y/N): ";
        cin >> prompt;

        if (prompt == 'Y' || prompt == 'y')
        {
            //Keeps program loop running.
            break;
        }
        else if (prompt == 'N' || prompt == 'n')
        {
            //Breaks the program rule.
            lever = false;
            break;
        }
        else
        {
            //Keep loop running until valid input is given.
            continue;
        }
    }
}