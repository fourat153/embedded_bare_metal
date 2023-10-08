#include "stdio.h"
void Prime(int a, int b);
int main() {
  int a, b;
  printf("enter interval a and b ");
  scanf("%d%d", &a, &b);
  Prime(a, b);
  return 0;
}

void Prime(int a, int b) {
  for (int i = a; i <= b; i++) {
    int flag = 0;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        break;
      } else {
        flag++;
      }
    }
    if (flag == i - 2) {
      printf("%d ", i);
    }
  }
}