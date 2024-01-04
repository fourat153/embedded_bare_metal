#include "dc_motor.h"


static int dc_speed = 0;
void (*dc_state)();

int DC_init()
{

    printf("dc motor init is done ");
} 


void DC_Set_speed(int speed)
{
	dc_speed = speed;
	dc_state = ST_STATE(dc_busy);
	printf("CA --------- Speed = %d -------> DC \n", dc_speed);
}




State_define(dc_busy);
{
    dc_state_id x = dc_busy ;
    printf("dc_busy state  speed =%d" ,dc_speed);
    dc_state = state(dc_idle);
    
    

}
State_define(dc_idle)
{
    dc_state_id x = dc_idle ;
	Dprintf("CA_idle State: speed = %d\n", dc_speed);


}
