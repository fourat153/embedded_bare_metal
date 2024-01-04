#ifndef __UART_H__
#define __UART_H__

#define UART *((volatile unsigned int *  ) ((unsigned int *)0x101f1000))


void uart_send (unsigned char * string ); 



#endif 