#include "stdio.h"
int main() {
  float num1, num2 = 0.0;
  printf("Enter two numbers:");
  scanf("%f%f", &num1, &num2);
  printf("sum : %0.6f", num1 * num2);
}