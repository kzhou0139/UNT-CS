#include "Lab8_Header.h"

/*
 Function:  computeMaximum
 Parameters:  a float array with the students' grades, an int that represents the number of students. and a float array that is empty but will end up including the maximum score for each student
 Return:  nothing
 Description: This function finds the maximum score for each student and puts it into an array
*/
void computeMaximum (float grades[][COLS], int num, float maximum[]) {
    for (int i = 0; i < num; i++) { //student
        int max = 0;
        for (int j = 0; j < COLS; j++) { //grade
            if (grades[i][j] > max)
                max = grades[i][j];
        }
        maximum[i] = max;
    }
}