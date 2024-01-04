#include "stdio.h"
int main() {
  int n ;
  n = n  + 1 ; 
  printf("enter size of array");
  scanf("%d", &n);
  int arr[n];
  printf("enter array elements");
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    arr[i] = t;
  }
  int pos;
  printf("enter element pos");
  scanf("%d", &pos);
  printf("enter new element ");
  int new;
  scanf("%d", &new);
  int flag = 0;
  for (int i = 0; i <= n; ++i) {
    int temp;
    int temp2;
    if (i == pos - 1   ) {
      temp = arr[i];
      arr[i ] = new;
      flag = 1;
    }
    else if  (flag) {
      temp2 = temp;
      temp = arr[i];
      arr[i] = temp2;
    }
  }

  for (int i = 0; i <= n; i++) {
     printf("%d " ,arr[i]);
   
}}