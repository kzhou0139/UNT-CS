/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        11 November 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Dynamic Arrays - make a dynamic array and create a function that returns the max value in the dynamic array.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Employee {
    string name;
    double salary;
};

int main() {
    ifstream data;
    data.open("data.dat");
    if(data.fail()) {
        cout<<"Error: could not open this file."<<endl;
        exit(EXIT_FAILURE);
    }

    double sum = 0;
    int count = 0;
    while (!data.eof()) {
        Employee* emp = new Employee;
        getline(data, emp->name, ',');
        count++;
        data>>emp->salary;
        sum += emp->salary;
        cout<<emp->name;
        cout<<"     $"<<emp->salary;
    }
    cout<<endl;
    double avg = sum / count;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"The average salary is $"<<avg<<endl;

    data.close();

    return 0;
}

