/*Benjamin Branch*/
/*CSC215         */
/*Jumanji, the classic board game?*/
/*The one from the kids book?     */
// Declare the libraries we need in this case 
// iostream and string
#include <iostream>
#include <string>

// declare the commands from the std library we want to use so we don't have to keep
// typing them out
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    // Declare variables for money, player number, players dead, survivors
    // and the player name
    const int GOLD_PIECES = 9000000;
    int adventurers, killed, survivors, gold_paid, gold_kept;
    string leader;

    // Prompt for info
    cout << "Welcome to Jumanji!!!\n\n";
    cout << "Enter the folowing to play\n";

    cout << "Enter a number: ";
    cin >> adventurers;

    cout << "Enter a number smaller than the first: ";
    cin >> killed;

    // Do calculations
    survivors = adventurers - killed;
    gold_kept = GOLD_PIECES % survivors;
    gold_paid = GOLD_PIECES - gold_kept;
    
    cout << "Please Enter the Name of your Chosen Character: ";
    cin >> leader;

    /*Begin story text.*/
    cout << "\nYou and your " << adventurers << " friends are sucked into ";
    cout << "the video game Jumanji, because only weird nerds play board games.\n";
    cout << "You were going to play as " << leader << ", but instead you are Dwayne 'The Rock' Johnson\n";
    cout << "You persue a fruitful career in the WWE and earn " << GOLD_PIECES << " USD making sure jabronis know their role.\n";
    cout << "Your dumb friends play the game and " << killed << " of them all succumb to the awful murder/death/plague of the jungle.\n";
    cout << "Out of the kindness of your heart you agree pay the grieving families "<< gold_paid <<" dollars and have " << gold_kept; /*I know the example had an inline calculation and know I can do that. */
    cout << " dollars left.\nGood job, Dwayne!";
    /*End story text. */

    // end main
    return 0;
}

