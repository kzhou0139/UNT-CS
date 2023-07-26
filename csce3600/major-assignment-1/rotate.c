// Group 10: Kelly Zhou
// CSCE 3600.002, Spring 2023
// Major Assignment 1, 3/23

// include directives
#include "major1.h"
#include <stdio.h>

// rotate function, rotates number to the right by rotateAmount bit positions
void rotate(long number, int rotateAmount) {
  // rotated variable will store the final value of number rotated rotateAmount
  // to the right
  unsigned int rotated = 0;
  // performs the right rotation
  // if the value of number right-shifted rotateAmount is 1
  // or if the value of number left-shifted by (32 - rotateAmount) is 1
  // 1 is appended to rotated's bit value
  // otherwise 0 is appended to rotated's bit value
  rotated = (number >> rotateAmount) | (number << (32 - rotateAmount));
  // print out the value of rotated
  printf("%ld rotated by %d position(s) gives: %u", number, rotateAmount,
         rotated);
}
