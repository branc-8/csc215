/*Benjamin Branch             */
/*CSC215                      */
/*Cyber Land Network          */
/*Header and source           */
/*headerAndSource.cpp         */


// include libraries and other files for project, primarily focusing on prototlypes
// and classes
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Source.cpp"
#include "Header.h"
// Main
int main()
{
    // Introduction and initialize player
    cout << "Welcome to Cyber Land Network!\n";
    string yourName = askText("Enter your name!\n> ");
    Player youAre(yourName, 100);
    cout << youAre.getName() << ", welcome to the information highway!\n";
    // First "level"
    Level entrance(
        "You just got sucked into your computer!",
        "Like That Movie!",
        "You see a guy throw a disk at you!",
        "Throw yours back?!",
        "Fight(1) Run(2)"
    );
    // Print the above text.
    entrance.printLevel();
    // While loop which allows for making a choice between
    // only two options
    int entranceQualifier = 0;
    while (!entranceQualifier)
    {
        int gate = askNumber("Choose wisely: ");
        if (gate == 1)
        {
            // adds money and ends loop
            youAre.earnMoney();
            entranceQualifier = 1;
        }
        else if (gate == 2)
        {
            // lose condition shows money and tells you that you lost
            cout << youAre.getName() << " is derezzed.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            return 0;
        }
    }
    //Level 2 same as above essentially
    Level gateway(
        "You derezz the sucker who would challenge you",
        "And now you see a light bike pass by",
        "You quickly figure out how to get on yours",
        "You are now challenging the other ridder",
        "Cut Them Off(1) Try To Keep Distance(2)"
    );
    gateway.printLevel();
    int gatewayQualifier = 0;
    while (!gatewayQualifier)
    {
        int lava = askNumber("Choose wisely: ");
        if (lava == 1)
        {
            // earn more money for this one
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            gatewayQualifier = 1;
        }
        else if (lava == 2)
        {
            cout << youAre.getName() << " is derezzed.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            return 0;
        }
    }
    // Level 3
    Level spooky(
        "And another one bites the dust.",
        "Next you are attacked by Space Invaders! Or Paranoids? Which ever!",
        "You see an unatended one nearby.",
        "No time to think! One is swooping right at you",
        "Hijack a Paranoid (1) Hide (2)"
    );
    spooky.printLevel();
    int spoopQualifier = 0;
    while (!spoopQualifier)
    {
        int bones = askNumber("Choose wisely: ");
        if (bones == 1)
        {
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            spoopQualifier = 1;
        }
        else if (bones == 2)
        {
            cout << youAre.getName() << " is derezzed.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            return 0;
        }
    }
    // Level 4
    Level dragon(
        "You get out of there and fly on to the MCU",
        "It gloats a lot and sounds a lot like some guy you don't like at the office.",
        "It is basically asking you to throw a disk at it.",
        "What do you do?",
        "Make it Pay!1) Leave It(2)"
    );
    dragon.printLevel();
    int dragonQualifier = 0;
    while (!dragonQualifier)
    {
        int scales = askNumber("Choose wisely: ");
        if (scales == 1)
        {
            youAre.earnMoney();
            youAre.earnMoney();
            youAre.earnMoney();
            dragonQualifier = 1;
        }
        else if (scales == 2)
        {
            cout << youAre.getName() << " is derezzed.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            return 0;
        }
    }
    // Win
    Level finale(
        "You get out of the computer",
        "But your pockets feel heavy.",
        "You reach in and realize you collected real coins when you were in the computer!",
        "How rich are we? Reach in and look!",
        "Collect your Reward!(1)"
    );
    finale.printLevel();
    int lastQualifier = 0; // only one option for the ending
    int* ptr = &lastQualifier; // obligatory pointer
    while (!lastQualifier)
    {
        int dollars = askNumber("Choose wisely: ");
        if (dollars == 1) // can only choose 1
        {
            *ptr = 1;
        }
    }
    int goldTotal = youAre.getMoney(); // gets total money
    int& ref = goldTotal; // reference to total
    int display = end(ref); // gets randomized final total of large amount of gold
    cout << "Your grand total is " << display << " gold!\n"; // win condition and final score
    cout << "You can retire young!\n";
    return 0; // end program
}

string askText(string prompt) // function for string prompts
{
    string text;
    cout << prompt;
    cin >> text;
    return text;
}

int askNumber(string prompt) // function for asking numbers
{
    int num;
    cout << prompt;
    cin >> num;
    return num;
}
int end(int& earnings) // end random multiplier function
{
    srand(static_cast<unsigned int>(time(0))); // seed rng
    int multiplier = earnings * (rand() % 100 + 1); // get random number based on earned gold
    return multiplier; // return final treasure amount
}