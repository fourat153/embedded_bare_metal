#include "../RTOS/inc/My_RTOS_FIFO.h"



FIFO_Status FIFO_Init(FIFO_Buffer_t *fifo, Element_Type* Buffer, uint32_t length)
{
	if(!Buffer)
		return FIFO_Null;


	fifo->base = Buffer;
	fifo->head = fifo->base;
	fifo->tail = fifo->base;
	fifo->length = length;
	fifo->counter = 0;

	return FIFO_No_Error;


}



FIFO_Status FIFO_Enqeue(FIFO_Buffer_t *fifo, Element_Type Item)
{
	// Check if the FIFO is valid
	if(!fifo->base || !fifo->length)
		return FIFO_Null;

	// Full FIFO
	if((fifo->head == fifo->tail) && (fifo->counter == fifo->length))
		return FIFO_Full;


	*(fifo->tail) = Item;
	fifo->counter++;


	// Handle Circular Queue
	if(fifo->tail == ((uint32_t)fifo->base + (4*(fifo->length))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_No_Error;
}




FIFO_Status FIFO_Deqeue(FIFO_Buffer_t *fifo, Element_Type* Item)
{
	// Check if the FIFO is valid
	if(!fifo->base || !fifo->length)
		return FIFO_Null;

	// Empty FIFO(Nothing to deqeue)
	if(fifo->head == fifo->tail)
		return FIFO_Empty;

	*Item = *(fifo->head);
	fifo->counter--;


	// Circular deqeue
	if(fifo->head == ((uint32_t)fifo->base + (4*(fifo->length))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_No_Error;

}




FIFO_Status FIFO_Is_Full(FIFO_Buffer_t *fifo)
{

	if(!fifo->head || !fifo->base || !fifo->tail)
		return FIFO_Null;

	if(fifo->counter == fifo->length)
		return FIFO_Full;

	return FIFO_No_Error;
}
