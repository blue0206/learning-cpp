//Coded by Aayush Rai on 22 October 2023.
//This program takes numeric input via keyboard or file
//and implements Bubble Sort to sort them in ascending order.
//Will be updated in future .

#include <iostream>
#include <fstream>
#include <cstdlib>

const int MAX_ARRAY_SIZE {16};
//Maximum possible array size.

void swap(int& num1, int& num2);
//Swaps values of two array indices.

void bubble_sort(int a[], int size);
//Sorts the list using bubble sort.

void ask_input_type(char& prompt);
//Asks user whether to use file input
//or keyboard input.

void ask_output_type(char& prompt);
//Asks user whether to output sorted 
//array to output file or screen.

void file_input_array(int a[], int max_size, int& size_used);
//Takes unsorted numbers input from file
//and appends to array a[].

void screen_input_array(int a[], int max_size, int& size_used);
//Takes input from user via keyboard
//and appends to array a[].

void screen_output_sorted_array(int a[], int size);
//Outputs the sorted array to screen.

void file_output_sorted_array(int a[], int size);
//Outputs the sorted array to an output file.

void loop(bool& lever);
//Asks user whether to run program again.

int main()
{
    bool lever {true};
    while (lever)
    {
        //Initialize array with max size and used size.
        int arr[MAX_ARRAY_SIZE], size_used {};
        
        char input_type {}, output_type {};
        
        //INPUT
        {
            ask_input_type(input_type);
            if (input_type == 'f' || input_type == 'F')
            {
                //Takes input via file.
                file_input_array(arr, MAX_ARRAY_SIZE, size_used);
            }
            else if (input_type == 'k' || input_type == 'K')
            {
                //Takes input via keyboard.
                screen_input_array(arr, MAX_ARRAY_SIZE, size_used);
            }
        }

        bubble_sort(arr, size_used);    //Implement bubble sort.

        //OUTPUT
        {
            ask_output_type(output_type);
            if (output_type == 'f' || output_type == 'F')
            {
                //Print output in external file.
                file_output_sorted_array(arr, size_used);
            }
            else
            {
                //Print output on screen.
                screen_output_sorted_array(arr, size_used);
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

void bubble_sort(int a[], int size)
{
    int range {size}, greatest_number {}, greatest_index {};

    for (int i=0; i < size; i++)
    {
        //Set greatest_number to final index within range.
        greatest_number = a[range - 1];
        
        for (int j=0; j < range; j++)
        {
            if ((j == (range - 1)) && (a[greatest_index] > a[range - 1]))
            {
                //Swaps largest value into final index at the end of each pass.
                swap(a[j], a[greatest_index]);
            }
            else if (greatest_number < a[j])
            {
                //Store largest value in greatest_number and store the index
                //of array containing that value in greatest_index.
                greatest_number = a[j];
                //Store index for swapping in final pass of this loop.
                greatest_index = j;
            }
        }
        //At the final pass of outer loop, range becomes one and the next
        //greatest value is stored in greatest_index.
        if (range == 1)
        {
            //Final swap is done outside the loop because range has reached
            //sentinel value of 1.
            swap(a[0], a[greatest_index]);
        }
        //Reduce range by one after each pass of outer loop.
        range--;
    }
}

void ask_input_type(char& prompt)
{
    using namespace std;

    cout << "Enter 'f' for file input.\n"
         << "Enter 'k' for manual input via keyboard.\n";
    cin >> prompt;
}

void ask_output_type(char& prompt)
{
    using namespace std;
    
    cout << "Enter 'f' for file output.\n"
         << "Enter 's' for screen output.\n";
    
    cin >> prompt;
}

void file_input_array(int a[], int max_size, int& size_used)
{
    using namespace std;
    
    ifstream fin;
    fin.open("unsorted.dat");
    if (fin.fail())
    {
        cout << "FAILED!\n";
        exit (1);
    }

    int num {};
    //Take input till maximum array size is reached.
    while((size_used < max_size))
    {
        fin >> num;
        //In case file input size < max array size, break loop at end of file.
        if (fin.eof())
        {
            break;
        }
        //Store file input in array[size_used] where size_used is already 0.
        a[size_used] = num;
        //Increment size_used with each pass to store input in successive index.
        ++size_used;
    }

    fin.close();
}

void screen_input_array(int a[], int max_size, int& size_used)
{
    using namespace std;

    cout << "Enter one by one for your list. Enter non-digit to stop.\n";
    while (size_used < max_size)
    {
        cout << "Enter number: ";
        //Store input in array.
        cin >> a[size_used];
        ++size_used;
    }
}

void screen_output_sorted_array(int a[], int size)
{
    using namespace std;
    
    cout << "Sorted Array:\n";
    for (int index=0; index < size; index++)
    {
        cout << a[index] << '\n';
    }
}

void file_output_sorted_array(int a[], int size)
{
    using namespace std;

    ofstream fout;
    fout.open("sorted.dat");
    if (fout.fail())
    {
        cout << "FAILED!\n";
        exit (1);
    }

    int index {};
    fout << "Sorted Array:\n";
    while (index < size)
    {
        fout << a[index] << '\n';
        ++index;
    }    

    fout.close();
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
            lever = true;
            break;
        }
        else if (prompt == 'N' || prompt == 'n')
        {
            //End program loop.
            lever = false;
            break;
        }
        else
        {
            //Keep loop running until correct input is given.
            continue;
        }
    }
}