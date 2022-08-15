/* 
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date:   23 September 2021        
Instructor: Poli Nemkova and Solomon Ubani
Description: Character Operations - the user inputs a phrase and the computer checks if the phrase satisfies certain conditions.'
*/

#include <iostream>
using namespace std;

int main() {
    string in;
    bool correct = true;
    cout<<"Please enter a string: ";
    getline(cin, in);

    if (isalpha(in.at(0))) {
        if (!(in.at(0) >= 65 && in.at(0) <= 90)) {
            cout<<"The first character must be an uppercase letter."<<endl;
            correct = false;
        }
    }
    else {
        cout<<"The first character must be a letter."<<endl; 
        correct = false;
    }
    
    if (!(in.at(in.size() - 1) == 46)) {
        cout<<"The last character must be a period."<<endl;
        correct = false;
    }

    if (correct)
        cout<<"There are no errors in this string."<<endl;

    return 0;
}