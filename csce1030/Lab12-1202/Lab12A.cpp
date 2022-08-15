/*
Author:	Kelly Zhou (kellyzhou@my.unt.edu)
Date: 2 December 2021
Instructor: Poli Nemkova and Solomon Ubani
Description: File I/O using C library functions - find the number of chars, lines, and words in a file
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

int main() {
	char filename[50];
	cout<<"Enter the name of the file: ";
	cin>>filename;
	FILE *fp;
	fp = fopen(filename, "r");

	int chars = 0;
	int lines = 0;
	int words = 0;
	char c = getc(fp);
	int count = 0;
	while(c != EOF) {
		count++;
		if (c != ' ' && c != '\t' && c != '\n')
			chars++;
		if (c == '\n')
			lines++;
		if (c == ' ' || c == '\t' || c == '\n') 
			words++;
		c = getc(fp);
	}
	cout<<"This file contains "<<chars<<" chars, "<<lines<<" lines, and "<<words<<" words"<<endl;
	fclose(fp);


	return 0;
}