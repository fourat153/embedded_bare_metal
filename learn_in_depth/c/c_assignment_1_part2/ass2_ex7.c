#include "stdio.h"
int res = 1;
int main() {
  int i = 0;
  scanf("%d", &i);

  if (i < 0) {
    printf("negative number error");
  } else {
    for (int x = 1; x <= i; x++) {
      res = res * x;
    }
  }
  printf("result == %d ", res);
}