/* 
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date:   30 September 2021        
Instructor: Poli Nemkova and Solomon Ubani
Description: For Loop - find the number of vowels and consonants in a string that the user enters.
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    int isVowel = 0;
    int isConsonant = 0;
    cout<<"Enter a string: ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s.at(i))) {
            if (toupper(s.at(i)) == 'A' || toupper(s.at(i)) == 'E' || toupper(s.at(i)) == 'I' || toupper(s.at(i)) == 'O' || toupper(s.at(i)) == 'U')
                isVowel++;
            else
                isConsonant++;
        }
    }

    cout<<"The string you entered contains "<<isVowel<<" vowels and "<<isConsonant<<" consonants."<<endl;

    return 0;
}