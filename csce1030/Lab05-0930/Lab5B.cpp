/* 
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date:   30 September 2021        
Instructor: Poli Nemkova and Solomon Ubani
Description: Do While Loop - perform a mathematical calculation based off of user input. However, if the user enters an incorrect character, the do-while loop makes the user enter another character until the character is valid.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    enum Operation {Multiply = 'M', Add = 'A', Difference = 'D'};
    int result;
    int num1, num2;
    Operation my_operation;
    char choice;
    cout<<"Enter two integers: "; cin>>num1>>num2;
    do {
        cout<<"Enter the operation you want to perform ('M' = Multiply, 'A' = Add, 'D' = Difference): ";
        cin>>choice;
        my_operation = (Operation)choice;
        switch (my_operation) {
            case Multiply:
                result = num1 * num2;
                break;
            case Add:
                result = num1 + num2;
                break;
            case Difference:
                result = abs(num1 - num2);
                break;
            default:
                cout<<"The character that you entered was invalid, please try again."<<endl;
                break;
        }
    } while (choice != 'M' && choice != 'A' && choice != 'D');
    cout<<"The result of the operation is "<<result<<"."<<endl;
    return 0;
}