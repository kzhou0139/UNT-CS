/*
 * Author:  Kelly Zhou (kellyzhou@my.unt.edu)
 * Date: October 14, 2021
 * Instructor: Poli Nemkova and Solomon Ubani
 * Description: Two-Dimensional Arrays - find the minimum value in each row and column.
 */

#include <iostream>
#include <climits>
using namespace std;

int main() {
    const int ROW_SIZE = 2;
    const int COLUMN_SIZE = 5;
    int matrix[ROW_SIZE][COLUMN_SIZE];
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            cout<<"Enter data for row#"<<i+1<<" and column#"<<j+1<<": ";
            cin>>matrix[i][j];
        }
    }

    cout<<"You entered: "<<endl;
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++)
            cout<<matrix[i][j]<<"\t";
        cout<<endl;
    }

    for (int i = 0; i < ROW_SIZE; i++) {
        int min = INT_MAX;
        for (int j = 0; j < COLUMN_SIZE; j++) {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
        cout<<"Minimum for row#"<<i+1<<" is "<<min<<endl;
    }

    for (int i = 0; i < COLUMN_SIZE; i++) {
        int min = INT_MAX;
        for (int j = 0; j < ROW_SIZE; j++) {
            if (matrix[j][i] < min)
                min = matrix[j][i];
        }
        cout<<"Minimum for column#"<<i+1<<" is "<<min<<endl;
    }

    return 0;
}
