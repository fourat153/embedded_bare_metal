#include "stdio.h"
int fact(int a);
int main() {
  int a;
  printf("enter interval a");
  scanf("%d", &a);
  int res = fact(a);
  printf("%d", res);
  return 0;
}

int fact(int a) {
  if (a == 0) {
    return 1;
  } else {
    return a * fact(a - 1);
  }
}