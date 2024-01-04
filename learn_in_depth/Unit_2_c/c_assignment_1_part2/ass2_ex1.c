#include "stdio.h"
int main() {
  char *odd = "odd";
  int number = 0;
  printf("enter an integer you want to check\n");
  scanf("%d", &number);
  if (number % 2 == 0) {
    odd = "even";
  }
  printf("result =  %s", odd);
}