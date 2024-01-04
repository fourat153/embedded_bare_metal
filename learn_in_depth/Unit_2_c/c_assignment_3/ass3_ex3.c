#include "stdio.h"
int reverse(char a[]);
int main() {
  int n;
  char a[n];
  printf("enter lenth word\n");
  scanf("%d", &n);
  printf("enter word : ");
  scanf("%s", a);
  reverse(a);
  return 0;
}

int reverse(char a[]) {
  if (*(a) == '\0') {
    printf("%c", *(a));
  } else {

    reverse(++a);
    printf("%c", *(--a));
  }
}