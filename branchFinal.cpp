/*Benjamin Branch             */
/*CSC215                      */
/*Scary Dark Castle           */
/*Final Project Text Adventure*/
/*brinchFinal.cpp             */

// include libraries and other files for project, primarily focusing on prototlypes
// and classes
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "prototypes.cpp"
#include "Classes.h"
// Main
int main()
{
    // Introduction and initialize player
    cout << "Welcome to the Scary Dark Castle!\n";
    string yourName = askText("Enter your name!\n> ");
    Player youAre(yourName, 100);
    cout << youAre.getName() << ", welcome to peril!\n";
    // First "level"
    Level entrance(
        "You stand at the entrance of Doom!",
        "You are at a foreboding gate!",
        "You can walk through",
        "or you can run away!",
        "Fight(1) Flee(2)"
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
        else if(gate == 2)
        {
            // lose condition shows money and tells you that you lost
            cout << youAre.getName() << " lives to fight another day but is a coward.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            cout << "However, you lost your pride.\n";
            return 0;
        }
    }
    //Level 2 same as above essentially
    Level gateway(
        "You push through the entrance like the brave warrior you are",
        "You are such a rockstar. Oh yeah. But what is this?",
        "In order to proceed, you must jump over a stream of lava!",
        "It looks like it hurts a lot!",
        "Jump(1) Run Away(2)"
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
            cout << youAre.getName() << " lives to fight another day but is a giant coward.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            cout << "However, you lost your pride and your friends throw rocks at you.\n";
            return 0;
        }
    }
    // Level 3
    Level spooky(
        "You muster all your guts and jump right over the lava!",
        "You're sure you've never jumped so far in your life! Boy, that was hot!",
        "However, you barely gain your ballance when you are attacked by a skelleton!",
        "Skelletons are spooky, and that sword it has looks sharp!",
        "Show No Mercy(1) Ahhhhh! Skeleton! Hide!(2)"
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
            cout << youAre.getName() << " lives to fight another day but is a giant coward.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            cout << "However, you lost your pride and your signifigant other leaves you.\n";
            return 0;
        }
    }
    // Level 4
    Level dragon(
        "You prove to be far more muscular than the skeleton and push it aside!",
        "You have not time to think about the sad look it gave you as you charge further inward toward\ntreasure and riches never seen before!",
        "Minutes later you approach the final chamber and are greeted with the roar of a red dragon\nA fierce and powerful being with a hunger and greed that would drive the average human mad!",
        "You meet its gaze with a reckless disregard for your life.\nIt meets yours with an equally reckless disregard for your life!\nWhat do you do!?",
        "Charge Onward, to Victory(1) Are you crazy? That thing is going to eat me! I'm outta here!(2)"
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
            cout << youAre.getName() << " is roasted alive as the dragon senses their weakness.\n";
            cout << "You earned " << youAre.getMoney() << " gold pieces.\n";
            cout << "They keep your charred corpse company until the next adventurer picks them up.\n";
            return 0;
        }
    }
    // Win
    Level finale(
        "The dragon laughs at your puny attempts to hit it, but it seems to like you.",
        "Never has the dragon seen such pointless bravery in the name of the trinkets underneath it.",
        "It says you remind it of itself, and decides to befriend you by giving you some of its riches!",
        "After swaping stories about jumping over lava and pushing over skeletons with attitude, there is but one thing left!",
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
    cout << "Your grand total is " << display << " gold!"; // win condition and final score
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