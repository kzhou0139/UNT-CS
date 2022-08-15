/* 
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date:   23 September 2021        
Instructor: Poli Nemkova and Solomon Ubani
Description: Searching in a string - locate a substring within a larger string with the find() method.
*/

#include <iostream>
using namespace std;

int main() {
    string dir = "In this lab we will search inside C++ strings.";
    string sub;

    cout<<"Enter a substring to find within the larger string: ";
    cin>>sub;

    int index = dir.find(sub);
    if (index >= 0 && index <= dir.size() - 1)
        cout<<"\""<<sub<<"\" is found on index "<<index<<"."<<endl;
    else
        cout<<"Error: \""<<sub<<"\" is not found within the larger string."<<endl;
    
    return 0;
}