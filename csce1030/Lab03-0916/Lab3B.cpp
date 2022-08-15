/* 
Author:  Kelly Zhou (kellyzhou@my.unt.edu)
Date: 09/16/21
Instructor: Poli Nemkova and Solomon Ubani
Description: Flow of control. Use if/else statements to determine if the user's/random input is within a specific range.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int num;
    srand (time(NULL));

    cout<<"Enter a number between 200 and 300: ";
    cin>>num;

    if (num >= 200 && num <= 300) {
        int randNum = rand() % 101 + 200;
        cout<<"The generated number is: "<<randNum <<endl;
        if (randNum < num)
            cout<<"The randomly generated number is less than the value you entered."<<endl;
        else
            cout<<"The randomly generated number is greater than the value you entered."<<endl;
    }
    else
        cout<<"Error: the number you entered is outside of the range."<<endl;
    
    return 0;
}