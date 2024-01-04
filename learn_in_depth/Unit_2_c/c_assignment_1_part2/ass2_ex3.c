#include "stdio.h"
float res = 0 ; 
int main() {
 float a, b , c ; 
 scanf("%f%f%f",&a,&b,&c); 
 if (a >= b){
  if (a >= c) 
  {
    res = a ; 
  }
  else {
    res  = c;  
  }
  
 }
 else {
  if (b >= c ){
    res = b ; 
  }
  else {
    res = c; 
  }
 }
 printf("result is %f", res); 
 }