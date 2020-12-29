/*Benjamin Branch             */
/*CSC215                      */
/*Scary Dark Castle           */
/*Final Project Text Adventure*/
/*Classes.h                   */

// includes and file beginning
#ifndef CLASSES_H
#define CLASSES_H
#pragma once /* Default alternative to the ifndef/endif tags in visual studio.
 Kind of useful. From what I am reading not part of the standard but very
 widely supported: https://stackoverflow.com/questions/1143936/pragma-once-vs-include-guards*/
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// Player class
class Player
{
public:
    // Class Constructor
    Player(string nm, int mn)
    {
        setPlayerName(nm);
        setMoney(mn);
    }
    // set name function
    void setPlayerName(string nickName)
    {
        name = nickName;
    }
    // get name function
    string getName()
    {
        return name;
    }
    // set money used upon creation
    void setMoney(int moMoney)
    {
        money = moMoney;
    }
    // increment the money pot
    void earnMoney()
    {
        money = money + 100;
    }
    // show me the money
    int getMoney()
    {
        return money;
    }
private:
    // private variables
    string name;
    int money;
};
// Level class for showing text
class Level
{
public:
    // Level constructor
    Level(string line1, string line2, string line3, string line4, string option)
    {
        levelText(line1, line2, line3, line4, option);
    }
    // define level strings
    void levelText(string a, string b, string c, string d, string e)
    {
        ln1 = a;
        ln2 = b;
        ln3 = c;
        ln4 = d;
        options = e;
    }
    // print level strings
    void printLevel()
    {
        cout << "\n" << ln1 << "\n";
        cout << ln2 << "\n";
        cout << ln3 << "\n";
        cout << ln4 << "\n";
        cout << options << "\n";
    }

private:
    // private variables
    string ln1;
    string ln2;
    string ln3;
    string ln4;
    string options;
};
// end file
#endif 