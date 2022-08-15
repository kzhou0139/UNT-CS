//Kelly Zhou
//CSCE 1040.001 Homework 1
//Implementation Files: Hwk1.cpp, bubble.cpp
//Header files: student.h, bubble.h
//Data Files: grades
//Compile and execute: g++ *.cpp
//./a.out <grades

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"
using namespace std;

struct classStats {
	float mean = 0.0;
	float min = 0.0;
	float max = 0.0;
	float median = 0.0;
	char *name;
};

int main(int argc, char *argv[]) {

	classStats stat;
	student *stuPtr[19];
	for (int i = 0; i < 19; i++) {
		stuPtr[i] = (student*)malloc(sizeof(student));
		stuPtr[i]->first = (char*)malloc(20*sizeof(char));
		stuPtr[i]->last = (char*)malloc(20*sizeof(char));
	}
	char* className = (char*)malloc(15*sizeof(char));
	scanf("%s", className);

	for (int i = 0; i < 19; i++) {
		scanf("%s %s %d %d %d", stuPtr[i]->first, stuPtr[i]->last, &stuPtr[i]->exam1, &stuPtr[i]->exam2, &stuPtr[i]->exam3);
		float avg = (float)(stuPtr[i]->exam1 + stuPtr[i]->exam2 + stuPtr[i]->exam3) / 3;
		stuPtr[i]->mean = avg;
	}
	
	bubble(stuPtr, 19);

	float total = 0;
	for (int i = 0; i < 19; i++) 
		total += stuPtr[i]->mean;
	float avg = total / 19;
	stat.mean = avg;
	stat.min = stuPtr[0]->mean;
	stat.max = stuPtr[18]->mean;
	stat.median = stuPtr[9]->mean;
	stat.name = className;

	printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
	printf("%s MEAN:   %.2f  MIN:   %.2f  MAX:   %.2f  MEDIAN:   %.2f\n", stat.name, stat.mean, stat.min, stat.max, stat.median);
	for (int i = 0; i < 19; i++) 
		printf("%12s   %10s   %5.2lf\n", stuPtr[i]->first, stuPtr[i]->last, stuPtr[i]->mean);

	free(className);
	for (int i = 0; i < 19; i++) {
		free(stuPtr[i]->first);
		free(stuPtr[i]->last);
		free(stuPtr[i]);
	}

	return 0;
}