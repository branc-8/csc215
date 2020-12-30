/*Benjamin Branch                        */
/*CSC 215                                */
/*referencedHack.cpp                     */
/*Swaps variables by reference.          */
/*Also hacks bad guys and gives me money */
/*My definition of 'bad guy' is basically*/
/*anyone with more money than me.        */

// Call iostream
#include <iostream>
// using std namespace
using namespace std;

// Prototyping our functions
int transaction(int x);
void hackBalance(int& x, int& y);

int main() /*main */
{
	// Balance variables
	int myBalance = 15;
	int yourBalance = 900000;
	// Text and call our balances.
	cout << "Vew Our Balances\n";
	cout << "My account balance is: " << myBalance << " USD\n";
	cout << "Your account balance is: " << yourBalance << " USD\n\n";
	cout << "Now let's buy something!\n";
	// now call function to change balance
	myBalance = transaction(myBalance);
	yourBalance = transaction(yourBalance);
	cout << "My account balance is: " << myBalance << " USD\n";
	cout << "Your account balance is: " << yourBalance << " USD\n\n";
	// Text and call and a successful swap of variables through pointers
	hackBalance(myBalance, yourBalance); /* This is the function that steals your moneys */
	cout << "Well, that won't do....\n";
	cout << "CHANGE PLACES!\n";
	cout << "My account balance is: " << myBalance << " USD\n";
	cout << "Your account balance is: " << yourBalance << " USD\n\n";
	cout << "Thanks for the money, friend!\n\n\n";
	// return 0
	return 0;
}

// function takes 15 off of a variable
int transaction(int x)
{
	int tempX = x;
	tempX = tempX - 15;
	return tempX;
}

// Swaps two values by reference.
void hackBalance(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}