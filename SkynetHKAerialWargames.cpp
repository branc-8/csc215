/* Benjamin Branch                   */
/*Skynet HK=Aerial: Wargames         */
/*CSC215                             */
/*Multiplayer number guessing action!*/

//Declare needed libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
//Declare use of the standard library namespace
using namespace std;
// main
int main()
{
	// Declare variables for the search algorithm, random number generator, number of tries
	// and prediction.

	// First ones set up numbers for the search grid algorithm for the HK Aerial.
	int searchGridLowNumber = 0;
	int searchGridHighNumber = 65;
	// Initialize RNG and secret Number
	srand(static_cast<unsigned int>(time(0))); // seed rng
	int secretNumber = rand() % 64 + 1;
	// Next we initialize guess variables
	int aiGuess1 = 0; // Brand X AI's current linear guess.
	int aiGuess2 = 0; // Brand Y AI's current random guess.
	/*This search algorithm looks at the number between the high and low guesses possibilities*/
	int targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber; // Skynet's "Guess"
	//Next variables for guesses and tries for various counterparts
	int guess;            // Player guess
	int playerTries = 0;  // Number of player guesses
	int netTries = 0;     // Number of Skynet tries
	int brandXAITries = 0;// Number of brand X AI tries
	int brandYAITries = 0;// Number of Brand Y AI tries
	//String for if player wants to play again.
	string yesNo;
	//Begin program text
	cout << "Generate Random enemy location on 8x8 grid...\n";
	cout << "Skynet HK-Aerial Initializing software...\n";
	// Player guessing interface
	do
	{
		// Get the player guess.
		cout << "Search a location for the enemy.\n>";
		cin >> guess;
		// increment amount of tries.
		++playerTries;
		// Decide if player has guessed the number.
		// Give player guidance if a miss.
		// Start end of game if hit.
		if (guess > secretNumber)
		{
			cout << "Intel places enemy in a lower sector.\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Intel places enemy in a higher sector.\n";
		}
		else
		{
			cout << "\nThe enemy is located at location #" << secretNumber << " on 8x8 grid with 1-64 sectors.\n";
			cout << "You located the enemy in " << playerTries << " attempts.\n";
		}
	} while (guess != secretNumber);
	// Skynet HK Aerial guessing
	do
	{
		// Increment tries here so we can see "Ping 1"
		++netTries;
		// initialize search algorithm for this cycle
		targetLocationPrediction =
			((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		// Begin conditional to see if guess is too high or too low
		if (targetLocationPrediction > secretNumber) /*If too high...*/
		{
			searchGridHighNumber = targetLocationPrediction; // Assign the high number to this location
		}
		else if (targetLocationPrediction < secretNumber) /*If too low...*/
		{
			// Same as before but for searchGridLowNumber
			searchGridLowNumber = targetLocationPrediction;
		}
		else /*Set win condition.*/
		{
			cout << "Skynet HK-Aerial locaed the enemy in " << netTries << " attempts.\n";
		}
	} while (targetLocationPrediction != secretNumber); //Set loop condition.
	// Brand X AI Guessing
	do
	{
		// Increment loop.
		++aiGuess1;
		// Create seperate variable for number of tries for consistency and readability.
		brandXAITries = aiGuess1;
		// Check if we have reached the secret number.
		if (aiGuess1 == secretNumber)
		{
			cout << "Brand X AI located the enemy in " << brandXAITries << " attempts.\n";
		}
	} while (aiGuess1 != secretNumber); // Loop condition
	// Brand Y AI Guessing
	do
	{
		++brandYAITries;// Increment loop
		aiGuess2 = rand() % 64 + 1;
		if (aiGuess2 == secretNumber)
		{
			cout << "Brand Y AI located the enemy in " << brandYAITries << " attempts.\n";
		}
	} while (aiGuess2 != secretNumber); // Loop condition.
	// Prompt player if they want to play again.
	cout << "Would you like to play again?\n>";
	cin >> yesNo;
	// If player chooses y/Y, then restart game. Otherwise exit.
	if (yesNo == "Y" || yesNo =="y")
	{
		cout << "\nThe only winning move in this game is not to play...\n\n";
		main();
	}
	else
	{
		cout << "\ngoodbye\n";
		//main() return statement
		return 0;
	}
}