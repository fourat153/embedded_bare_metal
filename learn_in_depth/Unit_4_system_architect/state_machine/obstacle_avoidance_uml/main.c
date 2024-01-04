#include "state.h"

#include "obstaclav.h"

#include "ultrasonic.h"

#include "dc_motor.h" 

void setup() 
{
    int speed = 0 ; 
    int distance = 0; 

    us_init() ; 
    DC_init() ; 
    
    ca_state = ST_STATE_define(ca_waiting);
    us_state = State_define(dc_busy);
    dc_state = State_define(dc_state);

    
}
int main()
{
  setup();
   while (1)
   {
    us_state();
    ca_state();
    dc_state();
   }
   

    return 0 ;
}