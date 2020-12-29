/*Benjamin Branch                           */
/*CSC 215                                   */
/*Interactive Adventure                     */
/*Enter words that slightly change the story*/
/*Tried more but decided to at least get the
example in.                                 */


// Declare necessart libraries.
#include<iostream>
#include<string>

using namespace std;

// Prototype functions
string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);
// Main
int main()
{
    // Introduce game
	cout << "Welcome to your interactive adventure. \n\n";
	cout << "Please answer the following questions for your interactive story.\n";
    // Get and store info in variables with functions we made.
	string name = askText("Please enter a name: ");
	string place = askText("please enter a place: ");
	int number = askNumber("Please enter a number: ");
	string item = askText("Please enter an item: ");
	string doYouLive = askText("lived/died? ");
    // Call the story
	tellStory(name, place, number, item, doYouLive);

	return 0;
}
// Answer get function.
string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}
// Number get function.
int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}
// Story with variables entered by user.
void tellStory(string name, string noun, int number, string bodyPart, string verb)
{
	cout << "\nHere's your story:\n";
	cout << "You are the giant bird ";
	cout << name;
	cout << " who loved to fly around on";
	cout <<  "the skyline of ";
	cout << noun;
	cout << "\nwhen one day, the locals of ";
	cout << noun;
	cout << " got hungry for bird. ";
	cout << "Surrounded by ";
	cout << number;
	cout << " " << noun << " locals";
	cout << ",\nadrenaline rushed through ";
	cout << name;
	cout << "'s system so " << name << " pulled out their trusty " << bodyPart << ". \n";
	cout << name << " fought valiantly with their " << bodyPart;
	cout << ", until the ";
	cout << noun << " locals ";
	cout << "attacked all at once. \n";
	cout << "In the end, " << name << " " << verb << ".\n";
}