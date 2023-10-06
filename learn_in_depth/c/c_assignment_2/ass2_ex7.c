#include "stdio.h"
#include "string.h"
int main() {
  char string[1000] = "";
  scanf("%s", &string);
  int x = strlen(string);
  for (int i = x - 1; i >= 0; i--) {
    printf("%c", string[i]);
  }
}