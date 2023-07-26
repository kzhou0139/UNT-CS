// Group 10: Alicia Lin
// CSCE 3600.002, Spring 2023
// Major Assignment 1, due March 23

// include directives
#include "major1.h"
#include <limits.h>
#include <stdio.h>

// Counting Leading Zeroes function
void clz(long number) {

  int count = 0;         // stores number of leading zeroes
  int original = number; // stores original operand

  // while the first digit of number is not 1
  while (!(number & (~INT_MAX))) {
    // increment number of zeroes
    count++;
    // left-shift number to get rid of zero that was just counted
    number = number << 1;
  }

  // output number of zeroes
  printf("The number of leading zeroes in %d", original);
  printf(" is %d", count);
}
