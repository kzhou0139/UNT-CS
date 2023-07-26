// Group 10: Dhruv Chanana
// CSCE 3600.002, Spring 2023
// Major Assignment 1
// March 23, 2023

#include "major1.h"
#include <stdio.h>

// Endian swap function
void endian(long number) {
  // create temporary new number variable
  unsigned int original = number;
  unsigned int newNumber = 0;

  // iterate through all 4 bytes
  for (int i = 0; i < 4; i++) {
    // get byte i by rotating right by i bytes and storing in byte variable
    // use an unsigned char because it is only 1 byte
    unsigned char byte = original >> (8 * i);
    // add the byte back to the new number in the new, swapped position
    newNumber += byte << (8 * (3 - i));
  }

  // set number to the new number
  printf("Endian swap of %u is %u", original, newNumber);
}
