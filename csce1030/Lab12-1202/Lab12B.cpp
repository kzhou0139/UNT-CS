/*
Author:	Kelly Zhou (kellyzhou@my.unt.edu)
Date: 2 December 2021
Instructor: Poli Nemkova and Solomon Ubani
Description: File I/O, Macros and Command-Line Arguments in C
*/

#include <iostream>
#include <stdio.h>
using namespace std;

#define METERS_TO_FEET 3.28084
#define convert(x) x*METERS_TO_FEET

int main(int argc, char* argv[]) {
	FILE *fp;
	fp = fopen("meters.txt", "r");
	if (fp == NULL) {
		cout<<"There was an error when opening this file"<<endl;
		return -1;
	}

	FILE *out = NULL;
	out = fopen(argv[1], "w");
	if (out == NULL) {
		cout<<"There was an error when opening this file"<<endl;
		return -1;
	}

	double meter;
	while (fscanf(fp, "%lf", &meter) != EOF) {
		double feet = convert(meter);
		fprintf(out, "%0.3lf\n", feet);
	}

	return 0;
}