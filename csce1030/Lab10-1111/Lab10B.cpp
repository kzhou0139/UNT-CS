/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        11 November 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Dynamic Arrays - make a dynamic array and create a function that returns the max value in the dynamic array.
*/

#include <iostream>
using namespace std;

/*
Function:  maxVal
Parameters:  a dynamic int array that contains values, an int that represents the size of the array.
Return:  an int representing the largest value in the array.
Description: This function finds the largest value in an array.
*/
int maxVal(int* arr, int size) {
    int max = *arr;
    for (int i = 0; i < size; i++) {
        if (*(arr+i) > max)
            max = *(arr+i);
    }
    return max;
}

int main() {
    int size;
    cout<<"What is the size of the array?: ";
    cin>>size;

    int *numlist = new int[size];
    for (int i = 0; i < size; i++) {
        cout<<"Enter value "<<i+1<<": ";
        cin>>*(numlist+i);
    }
    int max = maxVal(numlist, size);
    cout<<"The max value in the array is "<<max<<endl;

    return 0;
}
