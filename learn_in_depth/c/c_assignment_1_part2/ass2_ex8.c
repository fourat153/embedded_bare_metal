#include "stdio.h"
char x;
int main() {
  printf("enter an operation sign\n");
  scanf("%c", &x);
  float a, b;
  printf("enter an integer a \n");
  scanf("%f", &a);
  printf("enter an integer b\n");
  scanf("%f", &b);

  switch (x) {
  case ('*'):
    printf("a *  b = %f \n", a * b);
    break;
  case ('/'):
    if (b == 0) {
      printf("erro divison by 0 ");
      break;
    } else {
      printf("a / b = %f \n", a / b);
      break;
    }

  case ('+'):
    printf("a + b = %f\n ", a + b);
    break;
  case ('-'):
    printf("a - b = %f \n", a - b);
    break;

  default:
    break;
  }
}