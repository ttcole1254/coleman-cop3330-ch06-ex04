/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Tyler Coleman
 */

/*
* Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a
* vector<Name_value> instead of two vectors.

* Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add
* the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if
* names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and
* terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.
*/

#include "std_lib_facilities.h"	
class Name_value {
    public:
        Name_value(string n, int s): name(n), score(s) { }
        string name;
        int score;
};

int main()
{
    try {
        vector<Name_value> scores;
        string n;
        int s;
        cout << "Enter a name followed by a score, separated by a space (ex. Jim 17). To finish, type NoName 0: ";
        while ((cin >> n >> s) && (n != "NoName")) {
            for (int i = 0; i < scores.size(); ++i) {
                if (n == scores[i].name) error("You cannot enter a name more than once.");
            }
            scores.push_back(Name_value(n, s));
        }
        for (int i = 0; i < scores.size(); ++i) {
            cout << "(" << scores[i].name << "," << scores[i].score << ")\n";
        }
    } catch (runtime_error e) {
        cout << e.what() << "\n";
    }
}