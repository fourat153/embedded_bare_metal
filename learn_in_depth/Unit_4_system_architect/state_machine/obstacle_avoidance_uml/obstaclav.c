#include "obstaclav.h" 



static int  ca_speed  = 0 ;
static int ca_threshold = 50 ; 
static int ca_distance = 0 ;


void (*ca_state)(); 

void us_get_distance(int distance )
{

    int ca_distance = distance ;

    if (ca_distance <= ca_threshold)
    {
        ca_state = state(ca_waiting) ; 
    }
    else
    {
        ca_state = state(ca_driving);
    }
    printf("us---------distance=%d------------ca" , ca_distance);
} 
State_define(ca_waiting)
{
       ca_state_id x = ca_waiting;

      printf("CA_	wating State: distance = %d, speed = %d\n", ca_distance, ca_speed);

      ca_speed = 0 ; 

      dc_motor_speed_set(ca_speed);

}

State_define(ca_driving)
{
    ca_state_id x = ca_driving ; 
    printf("CA_	driving State: distance = %d, speed = %d\n", ca_distance, ca_speed);
    ca_speed = 30 ; 

    dc_motor_speed_set(ca_speed);


}