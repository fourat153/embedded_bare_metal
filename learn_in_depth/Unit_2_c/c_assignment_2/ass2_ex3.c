#include "stdio.h"
int main() {
  int r , c ;
  printf("enter row and column\n"); 
  scanf("%d%d", &r  , &c ); 
  int arr[r][c] ; 
  printf("enter matrix \n"); 
  for (int i = 0 ; i < r ; i++)
  {
    for(int j = 0  ; j <c ; j++)
    {
       int temp ; 
       scanf("%d", &temp) ; 
       arr[i][j] = temp;
    }
  } 
   for (int i = 0 ; i < c ; i++)
  {
    for(int j = 0  ; j <r ; j++)
    { 
      printf("%d " ,  arr[j][i] );
    }
    printf("\n");
  } 



}