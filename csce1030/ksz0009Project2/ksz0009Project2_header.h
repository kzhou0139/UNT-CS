#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 5;
enum CHOICES {Add = 1, Remove = 2, Display = 3, Search = 4, Results = 5, Quit = 6};
struct Student {
    string name;
    int id;
    int numTestsTaken;
    int *testScores = new int[5];
    int avgScores;
};


void add_Student();
void remove_Student(int stuID);
void display();
void search(int stuID);
void exportResults();
int findMinimum(int grades[], int size);
int getNumber();