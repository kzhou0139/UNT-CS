/* 
Author:  Kelly Zhou (kellyzhou@my.unt.edu)
Date: 09/16/21
Instructor: Poli Nemkova and Solomon Ubani
Description: A small description in your own words that describe what the program does. Any  additional flags needed to allow the program to compileshould also be placed here.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    char a;
    char b;
    int c;
    int d;
    double e;
    double f;

    printf("Please enter charcter values for the variables a and b, respectively: ");
    scanf("%c %c", &a, &b);
    printf("Please enter integer values for the variables c and d, respectively: ");
    scanf("%d %d", &c, &d);
    printf("Please enter double values for the variables e and f, respectively: ");
    scanf("%lf %lf", &e, &f);

    printf("You entered: %c, %c, %d, %d, %lf, %e.\n", a, b, c, d, e, f);

    return 0;
}