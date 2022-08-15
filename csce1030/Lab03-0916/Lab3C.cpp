/* 
Author:  Kelly Zhou (kellyzhou@my.unt.edu)
Date: 09/16/21
Instructor: Poli Nemkova and Solomon Ubani
Description: Nested if-else. Compute the bonus for an employee based on their salary, number of years of experience, and satisfactory performance.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    char performance;
    int experience;
    double salary, bonus;

    printf("Enter the value for employee performance (y/n): ");
    scanf("%c", &performance);
    printf("Enter the value for employee experience: ");
    scanf("%d", &experience);
    printf("Enter the value for employee salary: ");
    scanf("%lf", &salary);

    if (performance == 'Y' || performance == 'y') {
        if (experience >= 10)
            bonus = salary * 0.10;
        else
            bonus = salary * 0.05;
    }
    else {
        if (experience >= 10)
            bonus = salary * 0.03;
        else
            bonus = 0;
    }

    printf("This employee received a bonus of $%.2lf\n.", bonus);

    return 0;
}