#include "ultrasonic.h" 
#include "state.h"



 int distance = 0 ; 
void us_init() 
{
 
   printf("us init done");


}
State_define(us_busy)
{
    us_state_id x = us_busy;
    distance =  ultrasonic_get_distance_random(45 , 55 , 1);
    printf("US_busy State: distance = %d \n", distance);
    us_distance_set(distance); 
    us_state = State(us_busy);

}
int ultrasonic_get_distance_random(int min, int max, int count)
{
	// this will generate random number in range between start & end in number of counter
	int i;
	for (i = 0; i < count; i++)
	{
		int rand_num = (rand() % (max - min + 1)) + min;
		return rand_num;
	}
	return 0;
}