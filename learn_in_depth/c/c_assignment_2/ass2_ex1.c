#include "stdio.h"
int main() {
  float a, b, c, d;
  float f, g, j, h;
  printf("enter element matrix 1\n");
  scanf("%f%f%f%f", &a, &b, &c, &d);
  printf("enter element matrix 2 \n");
  scanf("%f%f%f%f", &f, &g, &h, &j);
  float matrix1[2][2] = {{a, b}, {c, d}};
  float matrix2[2][2] = {{f, g}, {h, j}};
  printf("sum of the matrix 2 * 2 = \n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%f     ", matrix1[i][j] + matrix2[i][j]);
    }
    printf("\n"
  }
}