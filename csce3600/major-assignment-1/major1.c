// Group 10: Dhruv Chanana, Alicia Lin, Kelly Zhou, Mark White
// CSCE 3600.002, Spring 2023
// Major Assignment 1, due March 23

// include directives
#include "major1.h"
#include <stdbool.h>
#include <stdio.h>

// main function
int main(void) {

  // menu loop
  while (true) {

    // initial menu statement
    printf("Enter the menu option for the operation to perform: \n (1) Count "
           "Leading Zeroes \n (2) Endian Swap \n (3) Rotate-right \n (4) "
           "Parity \n (5) EXIT \n --> ");

    // take user's menu option
    int option;
    scanf("%d", &option);

    // Option 1: Count Leading Zeroes
    if (option == 1) {

      // prompt for and take in integer operand
      printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
      long number;
      scanf("%ld", &number);

      // test if operand is in range; ask again if not
      if (number < 1 || number > 4294967295) {
        printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
        scanf("%ld", &number);
        while (number < 1 || number > 4294967295) {
          printf(
              "Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
          scanf("%ld", &number);
        }
      }

      // pass operand to Count Leading Zeroes function
      clz(number);
    }

    // Option 2: Endian Swap
    else if (option == 2) {

      // prompt for and take in integer operand
      printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
      long number;
      scanf("%ld", &number);

      // test if operand is in range; ask again if not
      if (number < 1 || number > 4294967295) {
        printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
        scanf("%ld", &number);
        while (number < 1 || number > 4294967295) {
          printf(
              "Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
          scanf("%ld", &number);
        }
      }

      // pass operand to Endian Swap function
      endian(number);
    }

    // Option 3: Rotate-right
    else if (option == 3) {

      // prompt for and take in first integer operand
      printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
      long number;
      scanf("%ld", &number);

      // test if first operand is in range; ask again if not
      if (number < 1 || number > 4294967295) {
        printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
        scanf("%ld", &number);
        while (number < 1 || number > 4294967295) {
          printf(
              "Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
          scanf("%ld", &number);
        }
      }

      // prompt for and take in second integer operand
      printf("Enter the number of positions to rotate-right the input (between "
             "0 and 31, inclusively): ");
      int rotateAmount;
      scanf("%d", &rotateAmount);

      // test if second operand is in range; ask again if not
      if (rotateAmount < 0 || rotateAmount > 31) {
        printf("Enter the number of positions to rotate-right the input "
               "(between 0 and 31, inclusively): ");
        scanf("%d", &rotateAmount);
        while (rotateAmount < 0 || rotateAmount > 31) {
          printf("Enter the number of positions to rotate-right the input "
                 "(between 0 and 31, inclusively): ");
          scanf("%d", &rotateAmount);
        }
      }

      // pass operands to Rotate-right function
      rotate(number, rotateAmount);
    }

    // OPTION 4: Parity

    else if (option == 4) {

      // Prompt for integer input
      int num;
      printf("Enter a 32-bit number between 1 and 4294967295: ");
      scanf("%d", &num);

      // Output parity
      printf("Parity of %d is %d\n", num, parity(num));

    }

    // Option 5: Quit
    else if (option == 5) {
      printf("Program terminating. Goodbye... \n");
      break;
    }

    // if option not in menu
    else {
      printf("Error: Invalid option. Please try again.");
    }
    printf("\n");
  }

  return 0;
}
