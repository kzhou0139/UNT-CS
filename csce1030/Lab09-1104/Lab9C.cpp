/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        4 November 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Array Sorting - take values from the input file, sort them in ascending order, put them into the output file
*/

#include <iostream>
#include <fstream>
using namespace std;

/*
 Function:  ascending
 Parameters:  a double array representing the values from the input file, an int count variable representing the number of elements in the values array
 Return:  nothing (void), but changes the order of the values in the vals array
 Description: This function rearranges the values in the val array into ascending order
*/
void ascending(double vals[], int count) {
    int temp = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (vals[j] < vals[i]) {
                temp = vals[j];
                vals[j] = vals[i];
                vals[i] = temp;
            }
        }
    }
}

int main() {
    ifstream nums;
    nums.open("unsorted.dat");
    ofstream order;

    double vals[100];
    int count = 0;
    nums >> vals[count];
    while (!nums.eof()) {
        nums >> vals[count];
        count++;
    }

    ascending(vals, count);

    char output_file[15];
    cout<<"Enter the name of the output file: ";
    cin>>output_file;
    order.open(output_file);

    for (int i = 0; i < count; i++)
        order<<vals[i]<<endl;

    nums.close();
    order.close();

    return 0;
}

