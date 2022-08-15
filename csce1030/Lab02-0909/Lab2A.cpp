/*
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date: 9 September 2021
Instructor: Poli Nemkova
Description: declare variables of various types and assign values to them.
*/

#include <iostream>
using namespace std;

int main () {
    int var1;
    char var2;
    double var3;
    double var4;

    var1 = 30;
    var2 = 'Z';
    var3 = 4.5;
    var4 = var3 + var2 % var1;

    cout<<"Var4: "<<var4<<endl;

    return 0;
}