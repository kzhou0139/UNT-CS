#include <stdio.h>

int main(void) {
  unsigned char val;
  printf("Enter an ASCII character: ");
  scanf("%c", &val);
  printf("The ASCII value of %c is:\n", val);
  printf("\tdec -- %d\n", val);
  printf("\thex -- %x\n", val);
  printf("\tbin -- ");

  for (int i = 7; i > -1; i--) {
      int valShift = val>>i;
    if (valShift & 1)
      printf("1");
    else
      printf("0");
  }
  printf("\n");

  return 0;
}
