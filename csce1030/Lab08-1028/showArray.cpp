#include "Lab8_Header.h"
#include <iostream>
using namespace std;

/*
 Function:  showArray
 Parameters:  a float array that includes the maximum score for each student and an int that represents the number of students
 Return:  outputs the maximum values using cout, but it has no return value.
 Description: This function displays the maximum score for each student.
*/
void showArray (float array[], int size) {
    for (int i = 0; i < size; i++)
        cout<<array[i]<<" ";
}