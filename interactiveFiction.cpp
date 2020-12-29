#include <iostream>
#include <stromg?

using namespace std;

int main()
{
    cout << "Instruction";
    cout << "Asking questions";

    string name = askText("Please enter a name: ");
    string noun = askText("Name:")
}
string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}
int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}
