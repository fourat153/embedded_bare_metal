#ifndef __ULTRASONIC__ 
#define __ULTRASONIC__


#include "state.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum{

    us_busy,
}us_state_id;

int ultrasonic_get_distance_random(int r , int l , int count); 

void us_init();


State_define(us_busy);
void (*us_state) ();

#endif