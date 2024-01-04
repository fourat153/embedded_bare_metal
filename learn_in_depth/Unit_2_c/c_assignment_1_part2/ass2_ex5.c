#include "stdio.h"
int main() {
  char a ;
 printf("enter a caractere ") ; 
  scanf("%c" , &a); 
  if (( a >= 'a' && a <= 'z' ) || (a >= 'A' && a<= 'Z')) 
  {
    printf("%c is alphabet" , a) ; 
  }  
  else 
  {
    printf("%c is not a alphabet", a ) ; 
  }

 }