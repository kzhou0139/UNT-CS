// parity function
#include "major1.h"
#include <stdio.h>

int parity(int number) {
  int count = 0;
  for (int i = 0; i < 32; i++) {
    count += number % 2;
    number /= 2;
  }
  return count % 2;
}
