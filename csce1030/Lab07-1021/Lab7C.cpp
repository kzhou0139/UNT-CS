/*  Author:      Kelly Zhou (kellyzhou@my.unt.edu)
    Date:        21 October 2021
    Instructor:  Poli Nemkova and Solomon Ubani
    Description: A function with boolean return type: Ask the user to enter two strings then create a function that finds the sum of the ASCII characters in each string. Inform the user which string had a greater ASCII value.
*/

#include <iostream>
using namespace std;

/*
 Function:  isLarger
 Parameters:  two user-entered strings
 Return:  a boolean value representing which string has the higher ASCII character value.
 Description: This function loops through two strings and finds the sum of the ASCII characters in each string. Then, it returns a boolean value that represents which string has the higher ASCII value sum.
 */
bool isLarger(string s1, string s2) {
    int s1Val = 0;
    int s2Val = 0;
    for (int i = 0; i < s1.length(); i++)
        s1Val += s1.at(i);
    for (int i = 0; i < s2.length(); i++)
        s2Val += s2.at(i);

    if (s1Val > s2Val)
        return true;
    else
        return false;
}


int main() {
    string s1;
    cout<<"Please enter a string: ";
    getline(cin, s1);
    string s2;
    cout<<"Please enter another string: ";
    getline(cin, s2);

    if (isLarger(s1, s2))
        cout<<"s1 has a larger ASCII sum."<<endl;
    else
        cout<<"s1 does not have a larger ASCII sum."<<endl;

    return 0;
}

