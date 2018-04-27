/* Code Breaker Project
By: Joseph Mlinko
Class: CSC215 C++ Programming
Date: 4/25/2018*/



#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

int main()
{
	//Declare variables
	int playerGuessCount = 0;
	int compChoice = 0; //Holds the array number
	string wordHolder; //Holds the word choice so the array word doesn't get scrambled.
	string playerChoice;

	string keyWords[10] = { "Apple", "Banana", "Wolf", "Bench", "Towel", "Bowl", "Plate", "Tower", "Boat", "School" };

	random_device rd;

	//Display the opener
	cout << "=======================================================================\n";
	cout << "Welcome to Code Breaker CIA Training, new Recruit!\n";
	cout << "Programmed By: Joseph Mlinko\n";
	cout << "Date:          4/25/2018\n";
	cout << "=======================================================================\n";
	cout << "\n";

	//Seed the random number generator.
	mt19937 eng(rd());
	uniform_int_distribution<> distr(0, 10);

	//Displays game information to the user.
	cout << "Congratulations on joining the CIA, recruit! We're going to teach you basic code breaking!\n";
	cout << "In order to win, you must successfully break the code three times! We'll display to you a word that is randomized, you must tell us what the word is!\n";
	cout << "Generating your first word now!\n";

	for (int i = 0; i <= 2; i++)
	{
		//Randomly pick a word.
		cout << "Word successfully generated, good luck!\n";
		compChoice = distr(eng);
		wordHolder = keyWords[compChoice];
		random_shuffle(wordHolder.begin(), wordHolder.end());
		cout << "Your word is " << wordHolder << ". Please guess to what it is!\n";
		cin >> playerChoice;
		//A while loop to play until the user gets it right.
		while (playerChoice != keyWords[compChoice])
		{
			playerGuessCount++;
			cout << "Unfortunately that is incorrect, please try again!\n";
			cin >> playerChoice;
		}

		playerGuessCount++;
		cout << "Congratulations! You got it correct! You've guess correctly " << (i + 1) << " times. You've guessed a total of " << playerGuessCount << " times!\n";
	}
	cout << "You have completed your training! Congratulations!";
	cout << "Press any key to exit.\n";
	system("pause");
	return 0;
}
