/*
   Author:      Kelly Zhou (kellyzhou@my.unt.edu)
   Date:        4 November 2021
   Instructor:  Poli Nemkova and Solomon Ubani
   Description: Member Function get, put, fail, and eof - put the text from the input file into the output file, taking into account the tabs and spaces.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    char c = ' ';
    ifstream in_s;
    ofstream out_s;

    char input_file[15];
    cout<<"Enter the name of the input file: ";
    cin>>input_file;
    char output_file[15];
    cout<<"Enter the name of the output file: ";
    cin>>output_file;
    out_s.open(output_file);
    if (out_s.fail()) {
        cout<<"Unable to open output file "<<output_file<<endl;
        exit(EXIT_FAILURE);
    }
    in_s.open(input_file);
    if (in_s.fail()) {
        cout<<"Unable to open input file "<<input_file<<endl;
        exit(EXIT_FAILURE);
    }
    in_s.get(c);
    while (!in_s.eof()) {
        out_s.put(c);
        in_s.get(c);
    }

    in_s.close();
    out_s.close();

    return 0;
}
