/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        28 October 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Function calling another function -
 */

#include <iostream>
#include <ctime>
using namespace std;

/*
 Function:  getRandom
 Parameters:  None
 Return:  an int that represents a randomly generated number
 Description: This function receives no parameter and returns a randomly generated value between 1 and 100.
*/

int getRandom() {
    srand(time(NULL));
    return (rand() % 100) + 1;
}

/*
 Function:  compare
 Parameters:  an int representing the user's guess
 Return:  sentences using cout that tell the user the value of the randomly generated number and if the user's guess was less than, equal to, or greater than the randomly generated value.
 Description: This function compares the user's guess with a randomly generated value.
*/
void compare (int guess) {
    int rand = getRandom();
    string rel = "";
    if (guess > rand)
        rel = " larger than ";
    else if (guess < rand)
        rel = " smaller than ";
    else
        rel = " equal to ";
    cout<<"The random number was "<<rand<<"."<<endl;
    cout<<"Your guess was"<<rel<<"the random number."<<endl;

}

int main() {
    int guess = 0;
    cout<<"Please enter a guess value: ";
    cin>>guess;
    compare(guess);
    return 0;
}