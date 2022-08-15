/* 
Author:  Kelly Zhou (kellyzhou@my.unt.edu)
Date: 28 November 2021
Instructor: Poli Nemkova and Solomon Ubani
Description: Dynamic Arrays in C-Programming
*/ 

#include <iostream>
using namespace std;

int main() {
	char choice = 'Y';
	int count = 1;
	double* nums = (double*)malloc(sizeof(double));
	while (choice == 'Y') {
		nums = (double*)realloc(nums, sizeof(double) * count);
		printf("Enter a number: ");
		scanf("%lf", &nums[count-1]);
		printf("List of numbers:\n");
		double sum = 0;
		for (int i = 0; i < count; i++) {
			sum += nums[i];
			printf("%lf\n", nums[i]);
		}
		double avg = sum / count;
		printf("Updated average is: %lf\n", avg);
		printf("More numbers (Y/N)?: ");
		scanf(" %c", &choice);
		count++;
	}
	return 0;
}