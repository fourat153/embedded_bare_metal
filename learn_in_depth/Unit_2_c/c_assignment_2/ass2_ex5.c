#include "stdio.h"
int main() {
  int n ;
  printf("enter size of array");
  scanf("%d", &n);
  int arr[n];
  printf("enter array elements");
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    arr[i] = t;
  }
  int target; 
  printf("enter size of target");
  scanf("%d", &target);
  int pos = -1; 
  for (int i = 0 ; i < n ; i++)
  {
    if (target == arr[i]) 
    {
      pos =  i + 1 ; 
      break;
    }
  }
  printf("%d",pos);
   
}