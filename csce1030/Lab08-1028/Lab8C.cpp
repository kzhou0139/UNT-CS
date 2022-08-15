/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        28 October 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Multiple files -
*/

#include <iostream>
#include "Lab8_Header.h"
using namespace std;

int main() {
    float grades[ROWS][COLS];  //2D array for grades
    float maximum[ROWS]; //array to store maximum grade for each student

    int num; //number of students in the class, must not be more than 10
    cout<<"How many students are in the class?: ";
    cin>>num;

    for (int r = 0; r < num; r++) {
        for (int c = 0; c < COLS; c++) {
            cout<<"Enter QUIZ #"<<c+1<<" for STUDENT #"<<r+1<<": ";
            cin>>grades[r][c];
        }
    }

    computeMaximum(grades, num, maximum);
    for (int r = 0; r < num; r++) {
        for (int c = 0; c < COLS; c++)
            cout<<grades[r][c]<<" ";
        cout<<endl;
    }

    cout<<"The maximum grades:\n";
    showArray(maximum, num);
    cout<<endl;
    return 0;
}