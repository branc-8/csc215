/*Benjamin Branch*/
/*CSC215         */
/*Kewyords.cpp   */
// The classic word jumble game where the player can ask for a hint
// Except rewritten a bit for spies.

// Include iostream, string, cstdlib, and ctime
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Declare using the std namespace.
using namespace std;
// main
int main()
{
	// create our string array for for secret words to scramble and their corresponding hints
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"spy", "The thing you do."},
		{"toomanysecrets", "setecastronomy, Extra brownie points if this is what it actually encoded to."},
		{"explosions", "That thing our drones make."},
		{"screwed", "The thing the gov would be if I am really their main coder."},
		{"kungfu", "It's not karate."},
		{"mug", "You put coffee in this."},
		{"farnsworth", "TV or Futurama. Take your pick."},
		{"passport", "Please stop forgetting these. You are wasting our, erm, taxpayer dollars."},
		{"rave", "Because even we need loud parties with music sometimes."},
		{"socialmedia", "It basically does our job for us."}
	};
	// RNG initialize along with variables for each word
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	int choice1 = (rand() % NUM_WORDS);
	int choice2 = (rand() % NUM_WORDS);
	// Variables for each random word and hint.
	string theWord = WORDS[choice][WORD]; // word hint
	string theHint = WORDS[choice][HINT]; // guess hint
	string theWord1 = WORDS[choice1][WORD]; // word hint
	string theHint1 = WORDS[choice1][HINT]; // guess hint
	string theWord2 = WORDS[choice2][WORD]; // word hint
	string theHint2 = WORDS[choice2][HINT]; // guess hint
	// Scramble the first keyword.
	string jumble = theWord; 
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		//traversing through  word
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		// making two random indexes
		char temp = jumble[index1]; // store the first random index in temp
		jumble[index1] = jumble[index2]; // store index 2 of jumble in index 1 of jumble
		jumble[index2] = temp;           // store temp in jumble index2
	}
	// Scramble the second keyword repeating above steps
	string jumble1 = theWord1; 
	int length1 = jumble1.size();
	for (int i = 0; i < length1; ++i)
	{
		int index1 = (rand() % length1);
		int index2 = (rand() % length1);
		char temp1 = jumble1[index1];
		jumble1[index1] = jumble1[index2];
		jumble1[index2] = temp1;
	}
	// Scramble the third keyword repeating above steps.
	string jumble2 = theWord2;
	int length2 = jumble2.size();
	for (int i = 0; i < length2; ++i)
	{
		int index1 = (rand() % length2);
		int index2 = (rand() % length2);
		char temp2 = jumble2[index1];
		jumble2[index1] = jumble2[index2];
		jumble2[index2] = temp2;
	}

	// Give instructions.
	cout << "Welcome to the Keyword Training Program\n\n";
	cout << "Here you will be decrypting three simple anagrams.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "The first keyword is: " << jumble;
	// make guess variable
	string guess;
	// prompt user
	cout << "\nYour guess: ";
	cin >> guess;
	// while and if statement dealing with guessing the first word
	while (guess != theWord)
	{
		if (guess == "hint")
		{
			cout << theHint << "\n";
		}
		else
		{
			cout << "The keyword is " << jumble << "\n";
		}

		cout << "Your guess: ";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "You guessed it! The new keyword is " << jumble1 << "\n"; // introduce next word and prompt
		cout << "Your guess: ";
		cin >> guess;
	}
	// while and if statement dealing with guessing the second word
	while (guess != theWord1)
	{
		if (guess == "hint")
		{
			cout << theHint1 << "\n";
		}
		else
		{
			cout << "The keyword is " << jumble1 << "\n";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}
	if (guess == theWord1)
	{
		cout << "You guessed it! The new keyword is " << jumble2 << "\n";
		cout << "Your guess: ";
		cin >> guess;
	}
	// while and if statement dealing with guessing the third word
	while (guess != theWord2)
	{
		if (guess == "hint")
		{
			cout << theHint2 << "\n";
		}
		else
		{
			cout << "The keyword is " << jumble2 << "\n";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}
	if (guess == theWord2)
	{
		cout << "That's it! You guessed the last keyword!\n"; // win condition
	}
	// Congratulate and ask if they want to do it again.
	cout << "\nThanks for training. Would you like to train again?(Y/N)\n";
	cin >> guess;
	if (guess == "y" || guess == "Y")
	{
		cout << "Okkie dokkie!\n";
		main();
	}
	else
	{
		cout << "Bye!\n";
		return 0;
	}
}