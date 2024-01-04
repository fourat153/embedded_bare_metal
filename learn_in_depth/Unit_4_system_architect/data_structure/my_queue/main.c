#include "my_queue.h"
#include <stdio.h>

queue_t queue1;
int item = 1;
int item1 = 2;
int item2 = 3;
int item3 = 4;
int item4 = 5;
void *item5 ; 
int item6 = 7;
int item7 = 8;
int main() {

  status_t ret = queue_create(&queue1, 5);
  ret = enqueue(&queue1, &item);
  printf("%d\n", *(int *)queue1.array[0]); 
  ret = enqueue(&queue1, &item1);
  printf("%d\n", *(int *)queue1.array[1]); 
  ret = enqueue(&queue1, &item2);
   printf("%d\n", *(int *)queue1.array[2]); 
  ret = enqueue(&queue1, &item3);
   printf("%d\n", *(int *)queue1.array[3]); 
  ret = enqueue(&queue1, &item4);
  printf("%d\n", *(int *)queue1.array[4]);

  ret = dequeue(&queue1, &item5);
  ret = dequeue(&queue1, &item5);
  ret = enqueue(&queue1, &item6);
 ret = enqueue(&queue1, &item7);
  printf("%d\n", *(int *)queue1.array[0]); 
    printf("%d\n", *(int *)queue1.array[1]); 

  printf("%d\n", *(int *)queue1.array[2]); 

  printf("%d\n", *(int *)queue1.array[3]); 

  printf("%d\n", *(int *)queue1.array[4]); 
 




  

}