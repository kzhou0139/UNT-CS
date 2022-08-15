/*
    Author:      Kelly Zhou (kellyzhou@my.unt.edu)
    Date:        21 October 2021
    Instructor:  Poli Nemkova and Solomon Ubani
    Description: Working with C-Strings: Use string functions to find which string has a longer length.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[21];
    char s2[100];
    strcpy(s1, "This is programming.");
    cout<<"Please enter a string: ";
    cin.getline(s2, 99);

    int s1length = strlen(s1);
    int s2length = strlen(s2);
    cout<<s1length<<" "<<s2length<<endl;

    if (s1length == s2length) {
        cout<<"The two strings are the same length."<<endl;
        if (strcmp(s1, s2) == 0)
            cout<<"The two strings are identical."<<endl;
        else
            cout<<"The two strings are not identical."<<endl;
    }
    else {
        cout<<"The two strings are not the same length."<<endl;
        return 0;
    }



    return 0;
}
