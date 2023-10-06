#include "stdio.h"
#include "string.h"
int main() {
  char string[100];
  gets(string);
  char target;
  scanf("%c", &target);
  int res = 0;
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == target) {
      res++;
    }
  }

  printf("characters %c == %d ", target, res);
}