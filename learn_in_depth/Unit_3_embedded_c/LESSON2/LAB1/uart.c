#include "uart.h"

void uart_send (unsigned char * string )
{
    while (*string !='\0')
    {
        UART = (unsigned int )*string; 
        string++;
    }
}