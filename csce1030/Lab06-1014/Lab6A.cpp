/*
 * Author:  Kelly Zhou (kellyzhou@my.unt.edu)
 * Date: October 14, 2021
 * Instructor: Poli Nemkova and Solomon Ubani
 * Description: Arrays - find the heights of 12 students then calculate the average of the heights. Display the heights that are above the average height.
 */

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 12;
    int sum_height = 0;
    int height[SIZE];
    int above_average[SIZE];
    double average;
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        cout<<"Enter height in inches of student #"<<i+1<<": ";
        cin>>height[i];
        sum_height += height[i];
    }

    average = sum_height / SIZE;

    for (int i = 0; i < SIZE; i++) {
        if (height[i] > average)
            count++;
    }

    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        if (height[i] > average) {
            above_average[index] = height[i];
            index++;
        }
    }

    cout<<"You entered: "<<endl;
    for (int i = 0; i < SIZE; i++)
        cout<<height[i]<<" ";
    cout<<endl;

    cout<<"The average of these numbers is "<<average<<"."<<endl;
    cout<<"Above average: "<<endl;
    for (int i = 0; i < count; i++)
        cout<<above_average[i]<<" ";
    cout<<endl;

    return 0;
}
