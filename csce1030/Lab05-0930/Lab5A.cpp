/* 
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date:   30 September 2021        
Instructor: Poli Nemkova and Solomon Ubani
Description: While Loop - add the values between two randomly generated values (inclusive).
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    int first = (rand()%11) + 10;
    int second = (rand()%11) + 20;

    int sum = 0;
    int num = first;
    while (num <= second) {
        sum += num;
        num++;
    }

    cout<<"The two randomly generated numbers were "<<first<<" and "<<second<<". The sum of these two values is "<<sum<<endl;



    return 0;
}