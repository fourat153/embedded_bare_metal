#include "stdio.h"
int power(int n, int a);
int main() {
  int n = 0;
  int a = 0;
  printf("enter base number : ");
  scanf("%d", &n);
  printf("enter power number : ");
  scanf("%d", &a);
  int res = power(n, a);
  printf("Result =  %d ", res);
  return 0;
}

int power(int n, int a) {
  if (a == 1) {
    return n;
  } else {
    return n * power(n, a - 1);
  }
}