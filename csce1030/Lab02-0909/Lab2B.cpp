/*
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date: 9 September 2021
Instructor: Poli Nemkova
Description: calculate the volume of a sphere.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    double volume;
    double radius;
    double pi = 3.14159;
    cout<<"Enter the radius of the sphere (in cm): ";
    cin>>radius;

    volume = (4 * pi * pow(radius, 3)) / 3;

    cout<<"The volume of the sphere is: "<<volume<<" cubic cm"<<endl;

    return 0;
}