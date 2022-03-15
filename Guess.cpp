#include "Guess.h"

void Guess::GetInput()
{
	cout << "You have " << chances << " chance left. Make your guess : ";
	cin >> input;

	for (int i = 0; i < 5; i++)
	{
		input[i] = toupper(input[i]);
	}

	isValid(input); 
}

void Guess::isValid(string str)
{
	if (input.length() > 5 || input.length() < 5 || !wordList.CheckList(str)) {
		cout << "Invalid Word. Please ensure your guess is a valid 5 letter word. \n";
		GetInput(); 
	}

	else 
	{
		chances--;
		CheckInput(str);
	}
}

void Guess::CheckInput(string str)
{
	if (input == wordList.key)
	{
		cout << BACKGROUND(BackgroundColor::Green, input) << endl;
		cout << endl;
		cout << "Hurrah! You guessed the word in " << 6 - chances << " tries !" << endl;
		cout << endl;
	}

	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (input[i] == wordList.key[i])
			{

				cout << BACKGROUND(BackgroundColor::Green, FOREGROUND(ForegroundColor::Black, input[i]));
			}

			else if (wordList.key.find(input[i]) != string::npos)
			{
				cout << BACKGROUND(BackgroundColor::Yellow, FOREGROUND(ForegroundColor::Black, input[i]));
			} 

			else cout << BACKGROUND(BackgroundColor::Grey, FOREGROUND(ForegroundColor::Black, input[i]));
		}
		cout << endl;
		if (chances > 0) GetInput();
		else cout << "The correct answer was '" << wordList.key << "'. Would you like to play again? Y / N : ";
		cin >> repeat;
		Restart(repeat); 
	}
}

void Guess::Restart(string str)
{
	if (str == "Y" || str == "y")
	{
		cout << endl << "Selecting new Secret Word ... \n" << endl;
		chances = 6;
		wordList.SetKey();
		GetInput();
	}

	else cout << "See You Next Time!"; 
}


