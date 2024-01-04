#ifndef __OBSTACLAV__ 
#define __OBSTACLAV__


#include "state.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum{

    ca_waiting,
    ca_driving
}ca_state_id;

State_define(ca_driving);
State_define(ca_driving);

extern void (*ca_state)(); 


#endif