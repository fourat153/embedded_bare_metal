
#include "uart.h"
unsigned char string[100] = "hello world";
unsigned char string2[100] = "face";
int x;
// const int aaaa = 10 ;
int main() {
  uart_send(string2);
  return 0;
}
