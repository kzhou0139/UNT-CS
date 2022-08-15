/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        28 October 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Passing arrays to function - create an array of randomly generated values then pass it to the maxVal array to find the largest number in the array.
*/

#include <iostream>
#include <ctime>
using namespace std;

const int ARRAY_SIZE = 10;

/*
 Function:  maxVal
 Parameters:  an int array that represents the array of randomly generated values
 Return:  an int that represents the max value of the array
 Description: This function computes the max value in an array.
*/
int maxVal (int arr[]) {
    int max = -2147483647;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        int randNum = (rand() % 51) + 50;
        arr[i] = randNum;
    }
    for (int i = 0; i < 10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int max = maxVal(arr);
    cout<<"The maximum value in the array is "<<max<<"."<<endl;
    return 0;
}