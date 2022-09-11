#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	cout << "Welcome! This game is Rock Paper Scissors." << endl;
	cout << "Two players are needed to play this game." << endl;
	cout << "Press and enter 'R' for Rock, 'P' for paper, and 'S' for Scissors." << endl;
	cout << endl;
	
	string playerOne, playerTwo;
	cout << "Enter your name, Player One: ";
	cin >> playerOne;
	cout << "Enter your name, Player Two: ";
	cin >> playerTwo;
	
	char playerOneChoice, playerTwoChoice, initiate;
	
	cout << "Press and enter 'I' to initiate the match!" << endl;
	cin >> initiate;
	while ( initiate == 'I' || initiate == 'i')
	{
		cout << playerOne << ", enter your pick: ";
		cin >> playerOneChoice;
		cout << playerTwo << ", enter your pick: ";
		cin >> playerTwoChoice;
		
		if ((playerOneChoice == 'R' || playerOneChoice == 'r') && (playerTwoChoice == 'P' || playerTwoChoice == 'p'))
		{
			cout << playerTwo << " Wins! Paper covers Rock." << endl; 
		}
		else if ((playerOneChoice == 'R' || playerOneChoice == 'r') && (playerTwoChoice == 'S' || playerTwoChoice == 's'))
		{
			cout << playerOne << " Wins! Rock breaks Scissors." << endl; 
		}
		else if ((playerOneChoice == 'P' || playerOneChoice == 'p') && (playerTwoChoice == 'R' || playerTwoChoice == 'r'))
		{
			cout << playerOne << " Wins! Paper covers Rock." << endl;
		}
		else if ((playerOneChoice == 'P' || playerTwoChoice == 'p') && (playerTwoChoice == 'S' || playerTwoChoice == 's'))
		{
			cout << playerTwo << " Wins! Scissors cut Paper." << endl;
		}
		else if ((playerOneChoice == 'S' || playerOneChoice == 's') && (playerTwoChoice == 'R' || playerTwoChoice == 'r'))
		{
			cout << playerTwo << " Wins! Rock breaks Scissors." << endl;
		}
		else if ((playerOneChoice == 'S' || playerOneChoice == 's') && (playerTwoChoice == 'P' || playerTwoChoice == 'p'))
		{
			cout << playerOne << " Wins! Scissors cut Paper." << endl;
		}
		else
		{
			cout << "Nobody Wins! It's a TIE!" << endl;
		}
		cout << "Press 'I' to play another match!" << endl;
		cin >> initiate;
	}
		
	return 0;
}