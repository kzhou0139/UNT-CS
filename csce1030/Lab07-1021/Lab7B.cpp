/*  Author:      Kelly Zhou (kellyzhou@my.unt.edu)
    Date:        21 October 2021
    Instructor:  Poli Nemkova and Solomon Ubani
    Description: Working with functions: calculate the amount of bonus the user earns based on their base salary and years of experience.
*/

#include <iostream>
using namespace std;

/*
 Function:  calBonus
 Parameters:  a double representing base salary and an int representing years of experience.
 Return:  a double representing the amount of bonus the user earns.
 Description: This function computes the bonus money that the user earns based on their base salary and years of experience.
 */
double calBonus (double baseSalary, int experience) {
    if (experience > 10)
        return baseSalary * 0.06;
    else
        return baseSalary * 0.03;
}

int main() {
    double baseSalary;
    cout<<"What is your base salary?: ";
    cin>>baseSalary;
    int experience;
    cout<<"How many years of experience do you have?: ";
    cin>>experience;
    double userBonus = calBonus(baseSalary, experience);
    cout<<"You have received a bonus of $"<<userBonus<<"."<<endl;

    return 0;
}

