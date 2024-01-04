#include <stdint.h>
void rest_handler(); 
extern int main() ; 
void Default_handler() 
{
    rest_handler();
    
};

static uint32_t stack_top[256];
void NMI_handler(void)__attribute__((weak , alias("Default_handler")));;
void H_fault_handler(void)__attribute__((weak , alias("Default_handler")));;



void (*const g_p_fn_vectors[])() __attribute__ ((section(".vectors"))) =
{
	(void(*)())	((uint32_t )stack_top + sizeof(stack_top)),
    &rest_handler,
    &NMI_handler,
    &H_fault_handler
};
extern uint32_t _E_BSS;
extern uint32_t _S_BSS;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t E_TEXT;

void rest_handler()
{
    uint8_t *p_dest = (uint8_t*)&_S_DATA ; 
    uint8_t *p_source = (uint8_t*)&E_TEXT ;
    uint32_t size_data =  (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
    for(uint8_t i = 0 ; i < size_data ; i++)
    {
        *((uint8_t * )p_dest++) = *((uint8_t *)p_source++);
    }
        
    p_dest = (uint8_t * )&_S_BSS ;
    size_data = (uint8_t * )&_E_BSS - (uint8_t * )&_S_BSS;
    for (uint8_t i = 0 ; i < size_data ; i++)
    {
        *((uint8_t * )p_dest++)= (uint8_t) 0 ; 
    }


    main();
}





