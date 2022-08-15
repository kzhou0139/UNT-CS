/*
 * Author:  Kelly Zhou (kellyzhou@my.unt.edu)
 * Date: October 14, 2021
 * Instructor: Poli Nemkova and Solomon Ubani
 * Description: Sorting Arrays - reverse the order of an array based of ASCII characters
 */

#include <iostream>
using namespace std;

int main() {
    char arr[] = {'b', 'f', 'a', 'z', 'm', 'g', 'q', 't'};
    char temp;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < 8; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;


    return 0;
}


