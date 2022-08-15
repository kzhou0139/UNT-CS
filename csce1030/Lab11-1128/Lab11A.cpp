/* 
Author:  Kelly Zhou (kellyzhou@my.unt.edu)
Date: 28 November 2021
Instructor: Poli Nemkova and Solomon Ubani
Description: Two-dimensional dynamic arrays - find the average score of each student and display the value 
in the terminal. Uses pointer arrays.
*/ 

#include <iostream>
using namespace std;

/* 
Function:   getGrades 
Parameters: an int representing the number of students, an int pointer dynamic 2d array representing the 
test scores of the students, and a double pointer 1d array representing the average scores of the
students
Return:  doesn't return anything, stores the average scores of the students into the avg array
Description:   This function first asks the user for the number of tests taken by each student and allocates
enough room for each student's tests. Then, the function prompts the user for the scores of each test scored
by each student and then the average score is found among those values.
*/ 
void getGrades(int numStu, int** testScores, double* avg) {
   int numTests = 0;
   for (int i = 0; i < numStu; i++) {
      cout<<"How many tests has student#"<<i+1<<" taken?: ";
      cin>>numTests;
      testScores[i] = new int[numTests];

      int sum = 0;
      for (int j = 0; j < numTests; j++) {
          cout<<"Enter student#"<<i+1<<"'s score for test "<<j+1<<": ";
          cin>>testScores[i][j];
          sum += testScores[i][j];
      }
      avg[i] = sum / numTests;
   }   
}

/* 
Function:   dispAverage 
Parameters: a double pointer 1d array that represents the average score of each student, an int representing
the numbers of students
Return:  doesn't return anything, prints out the values in the avg array
Description:   This function loops through the values in the avg array and prints them out to the terminal
*/ 
void dispAverage(double* avg, int numStu) {
   for (int i = 0; i < numStu; i++)
      cout<<"The average for student#"<<i+1<<" is "<<avg[i]<<endl;
}

int main() {
   int numStu = 0;
   cout<<"Enter the number of students: ";
   cin>>numStu;

   int** testScores;
   testScores = new int*[numStu];
   double* avg = new double[numStu];

   getGrades(numStu, testScores, avg);
   dispAverage(avg, numStu);

   for (int i = 0; i < numStu; i++)
      delete [] testScores[i];
   delete [] testScores;
   delete [] avg;
   return 0;
}