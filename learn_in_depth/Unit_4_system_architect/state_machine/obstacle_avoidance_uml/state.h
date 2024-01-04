#ifndef __STATE_H__ 
#define __STATE_H__
#define State_define(_stateFunc_)  void ST_##_stateFunc_()


#define State(_stateFunc_)          ST_##_stateFunc_


#include <stdio.h>
#include <stdlib.h>

int us_distance_set(int d); 
int dc_motor_speed_set(int s);


#endif