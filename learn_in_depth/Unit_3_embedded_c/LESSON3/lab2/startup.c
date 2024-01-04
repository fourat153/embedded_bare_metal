#include <stdint.h>

void Reset_Handler(void) ;
extern int main (void );
uint32_t extern _stack_top; 
void Default_Handler()
{
	Reset_Handler();
}
void NMI_handler(void)__attribute__((weak , alias("Default_Handler")));;
void H_fault_handler(void)__attribute__((weak , alias("Default_Handler")));;
void MM_fault_handler(void)__attribute__((weak , alias("Default_Handler")));;
void Bus_fault(void)__attribute__((weak , alias("Default_Handler")));;
void Usage_fault_handler(void)__attribute__((weak , alias("Default_Handler")));;



uint32_t vectors[] __attribute__((section(".vectors")))  =
{
    (uint32_t) &_stack_top,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_handler, 
    (uint32_t) &H_fault_handler,
    (uint32_t) &MM_fault_handler, 
    (uint32_t) &Bus_fault, 
    (uint32_t) &Usage_fault_handler 

};
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
void Reset_Handler (void )
{
    unsigned int DATA_SIZE = (unsigned char * ) &_E_DATA - (unsigned char * )&_S_DATA;
    unsigned char  *p_src = (unsigned char * )&_E_text;
    unsigned char  *p_des = (unsigned char * )&_S_DATA;
    for(int i = 0 ; i <DATA_SIZE ; i++)
    {
        *((unsigned char * )p_des++)= *((unsigned char * )p_src++);

    }


    unsigned int bss_size = (unsigned char * )&_E_bss - (unsigned char * )&_S_bss ; 
    p_des = (unsigned char * )&_S_bss; 
    for (int i = 0 ;  i < bss_size ; i++)
    {
        *((unsigned char  * ) p_des++ ) = (unsigned char )0;
    }
    main(); 


}