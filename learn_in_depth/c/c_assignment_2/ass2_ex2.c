#include "stdio.h"
int main() {
  int n = 0;
  printf("enter number of data\n");
  scanf("%d", &n);
  float arr[n];
  for (int i = 0; i < n; i++) {
    float temp = 0;
    printf("%d . enter number : ", i + 1);
    scanf("%f", &temp);
    arr[i] = temp;
  }

  float res = 0;
  for (int i = 0; i < n; i++) {
    res += arr[i];
  }
  printf("average = %f", res / (float)n);
}