#ifndef INC_MY_RTOS_FIFO_H_
#define INC_MY_RTOS_FIFO_H_

#include "stdio.h"
#include "stdint.h"
#include "Schedular.h"

// Determined by the user
#define Element_Type Task_Config*   // Pointer to the task


typedef struct{
	uint32_t counter;
	Element_Type* head;
	Element_Type* tail;
	Element_Type* base;
	uint32_t length;
}FIFO_Buffer_t;


typedef enum{
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Empty,
	FIFO_Null
}FIFO_Status;



FIFO_Status FIFO_Init(FIFO_Buffer_t *fifo, Element_Type* Buffer, uint32_t length);
FIFO_Status FIFO_Enqeue(FIFO_Buffer_t *fifo, Element_Type Item);
FIFO_Status FIFO_Deqeue(FIFO_Buffer_t *fifo, Element_Type* Item);
FIFO_Status FIFO_Is_Full(FIFO_Buffer_t *fifo);

#endif /* INC_MY_RTOS_FIFO_H_ */
