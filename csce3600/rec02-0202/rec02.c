//Kelly Zhou
//ksz0009

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *int_ptr = (int*)malloc(2 * sizeof(int));
  if (int_ptr == NULL) {
    printf("Memory allocation failed.");
    exit(0);
  }

  printf("Enter the first integer: ");
  scanf("%d", &int_ptr[0]);
  printf("Enter the second integer: ");
  scanf("%d", &int_ptr[1]);

  printf("Original values: 1st = %d, 2nd = %d\n", int_ptr[0], int_ptr[1]);

  int_ptr[0] = int_ptr[0] ^ int_ptr[1];
  int_ptr[1] = int_ptr[0] ^ int_ptr[1];
  int_ptr[0] = int_ptr[0] ^ int_ptr[1];

  printf("Swapped values: 1st = %d, 2nd = %d", int_ptr[0], int_ptr[1]);

  free(int_ptr);

  return 0;
}
