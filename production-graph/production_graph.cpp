//Coded by Blue on 19 October 2023.
//This program takes input of production of each department in 4 plants
//and outputs a bar graph made of asterisk (*) showing total production for each
//plant. Each asterisk in graph equals 1000 units of production.


#include <iostream>
#include <cmath>


void get_sum(int& sum, int plant_number);
//Takes in indexed variable as reference parameter and index number as argument.
//Takes production amount for a single plant as input and returns the sum.

void get_input(int a[], int last_plant);
//Takes in production array and last plant as input.
//Calls get_sum() function and records total production amount for each plant
//in production array.

int to_round(double value);
//Rounds up or rounds down the total production of plants using
//floor() function and type casting.

void scale(int a[], int last_plant);
//Takes in production array containing total production of each plant
//and index number of last plant as arguments.
//Rounds up or rounds down the total production of each plant
//by dividing by 1000.0 and calling the to_round() function.

void plot_graph(int data);
//Plots the asterisk by taking in rounded production of each plant.

void graph(int a[], int last_plant);
//Takes in production array containing rounded value of total production
//and calls plot_graph() function to plot asterisk.

void run_again(char& response);
//Asks user whether to run program again.

int main()
{
    while (true)
    {
        int production[4], total_plants {4};

        get_input(production, total_plants);  
        //Gets total production of each plant in production array.

        scale(production, total_plants);    
        //Gets rounded value of total production of each plant in production 
        //array.

        graph(production, total_plants);
        //Outputs graph according to production of each plant.

        char prompt;
        run_again(prompt);
        if (prompt == 'N' || prompt == 'n')
        {
            break;
        }
    }

    return 0;
}

void run_again(char& response)
{
    using namespace std;

    while (true)
    {
        cout << "Run the program again? (Y/N): ";
        cin >> response;
        if (response == 'y' || response == 'Y' 
            || response == 'N' || response == 'n')
        {
            break;
        }
    }
}

void get_sum(int& sum, int plant_number)
{
    using namespace std;

    cout << "Enter the production of different departments of plant #"
         << plant_number << " one by one.\n"
         << "Enter a negative number to stop.\n";
    
    int input{};
    sum = 0;                    //Initialize sum at 0.
    while (input >= 0)          //Break loop for negative input.
    {
        sum += input;
        cout << "Enter production: ";
        cin >> input;
    }
}

void get_input(int a[], int last_plant)
{
    using namespace std;

    for (int plant_number = 1; plant_number <= last_plant; plant_number++)
    {
        cout << "Production of plant #" << plant_number << ":\n";
        get_sum(a[plant_number - 1], plant_number);
        //Gets sum of productions of each department of single plant.
    }
}

int to_round(double value)
{
    return (static_cast<int>(floor(value + 0.5)));
    //Rounds up numbers >= 0.5 and rounds down numbers < 0.5
}

void scale(int a[], int last_plant)
{
    for(int plant_number = 1; plant_number <= last_plant; plant_number++)
    {
        a[plant_number - 1] = 
        to_round(static_cast<double>(a[plant_number - 1])/1000.0);
        //Gets rounded value of total production of each plant.
    }
}

void plot_graph(int data)
{
    using namespace std;

    for (int count = 0; count < data; count++)
    {
        cout << "* ";
    }
    cout << '\n';
}

void graph(int a[], int last_plant)
{
    using namespace std;

    cout << "\nProduction Graph (1 asterisk ~ 1000 units):\n";
    for (int plant_number = 1; plant_number <= last_plant; plant_number++)
    {
        cout << "Plant #" << plant_number << ": ";
        plot_graph(a[plant_number - 1]);    
        //Plots graph for each plant via printing asterisk.
    }
    cout << '\n';
}