#ifndef __DC_MOTOR__ 
#define __DC_MOTOR__


#include "state.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum{

    dc_idle,
    dc_busy
}dc_state_id;

State_define(dc_idle);
State_define(dc_busy);
int DC_init(); 

extern void (*dc_state)(); 


#endif