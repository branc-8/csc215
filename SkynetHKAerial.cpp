/*Benjamin Branch */
/*Skynet HK=Aerial*/
/*CSC215          */
/*Why guess your number when you can
have the computer do it for you?  */

//Declare needed libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
//Declare use of the standard library namespace
using namespace std;
// main
int main()
{
	// Deckare variables for the search algorithm, random number generator, number of tries
	// and prediction.
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	srand(static_cast<unsigned int>(time(0))); // seed rng
	int secretNumber = rand() % 64 + 1;
	/*This search algorithm looks at the number between the high and low guesses possibilities*/
	int targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	int tries = 0;
	//Begin program text
	cout << "Generate Random enemy location on 8x8 grid...\n";
	cout << "The enemy is located at location #" << secretNumber << " on 8x8 grid with 1-64 sectors.\n";
	cout << "Skynet HK-Aerial Initializing software...\n";
	// Do while loop running the search algoithm and game text.
	do
	{
		// Increment tries here so we can see "Ping 1"
		++tries;
		cout << "--------------------------------------------------\n";
		cout << "HK-Arieal Radar Sending out ping #" << tries <<"\n";
		// initialize search algorithm for this cycle
		targetLocationPrediction =
			((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber; 
		// Begin conditional to see if guess is too high or too low
		if (targetLocationPrediction > secretNumber) /*If too high...*/
		{
			cout << "The target location prediction of "<< targetLocationPrediction << " was higher than the actual enemy location of " << secretNumber<< "\n";
			searchGridHighNumber = targetLocationPrediction; // Assign the high number to this location
			cout << "The new searchGridHighNumber -" << searchGridHighNumber <<"\n"; // Let the user know we did that
		}
		else if (targetLocationPrediction < secretNumber) /*If too low...*/
		{
			// Same as before but for searchGridLowNumber
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << secretNumber << "\n";
			searchGridLowNumber = targetLocationPrediction;
			cout << "The new searchGridLowNumber -" << searchGridLowNumber << "\n";
		}
		else /*Set win condition.*/
		{
			cout << "Enemy was hiding at location #" << secretNumber <<"\n";
			cout << "Target was found at location #" << targetLocationPrediction << "\n";
			cout << "Skynet HK-Aerial Software took " << tries << " predictions to find the enemy location on the grid size of 8x8 (64).\n";
		}
	} while (targetLocationPrediction != secretNumber); //Set loop condition.
	//main() return statement
	return 0;
}