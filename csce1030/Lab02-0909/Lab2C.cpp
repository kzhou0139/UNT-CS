/*
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date: 9 September 2021
Instructor: Poli Nemkova
Description: compute the bonus earned by an employee and display the result.
*/

#include <iostream>
using namespace std;

int main() {
    string name;
    double salary;
    int rate;
    double bonus;

    cout<<"Employee Name: ";
    getline(cin, name);
    cout<<"Employee Salary: ";
    cin>>salary;
    cout<<"Enter rate: ";
    cin>>rate;
    bonus = salary * (static_cast<double>(rate)/100);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<name<<" earned a bonus of $"<<bonus<<endl;
    return 0;
}