/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        11 November 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Structures - make a Patient struct to get the name, weight, and height of a patient. Then, use a function to see if the patient's BMI is within range or not.
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Patient {
    string name;
    float weight;
    int feet;
    int inches;
};

bool checkBMI(Patient);

int main() {
    Patient person;
    cout<<"Enter the patient's name: ";
    getline(cin, person.name);
    cout<<"Enter the patient's weight in pounds: ";
    cin>>person.weight;
    cout<<"Enter the patient's height in feet and inches: ";
    cin>>person.feet>>person.inches;

    if (checkBMI(person))
        cout<<"The BMI of "<<person.name<<" is within range."<<endl;
    else
        cout<<"The BMI of "<<person.name<<" is not within range."<<endl;

    return 0;
}

/*
Function:  checkBMI
Parameters: an object of Patient
Return:  a true/false value representing if a patient's BMI is within range
Description: This function checks if a patient's BMI is within range.
*/
bool checkBMI(Patient p) {
    int totalHeight = p.feet * 12 + p.inches;
    float bmi = (703 * p.weight) / pow(totalHeight, 2);
    return (bmi >= 18.5 && bmi <= 24.9);
}