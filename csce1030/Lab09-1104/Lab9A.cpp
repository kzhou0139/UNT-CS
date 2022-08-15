/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        4 November 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Reading Data From File - read values from a file and calculate the sum of each row.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream data;
    data.open("data.dat");

    int val1, val2, val3;
    while (data >> val1 >> val2 >> val3) {
        int sum = 0;
        sum += val1 + val2 + val3;
        cout<<sum<<endl;
    }
    data.close();
    return 0;
}
