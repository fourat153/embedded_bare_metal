#ifndef __MY_QUEUE__H
#define __MY_QUEUE__H

#include <stdlib.h>

typedef struct {
  void **array;
  int max_size;
  int reare;
  int front;
  int counter;
} queue_t;

typedef enum {
  queue_empty,
  queue_full,
  queue_ok,
  queue_not_ok,
} status_t;

status_t queue_create(queue_t *queue, int max_size);
status_t destroy_queue(queue_t *queue);
status_t enqueue(queue_t *queue, void *item);
status_t dequeue(queue_t *queue, void *item);
status_t queue_get_rear(queue_t *queue, void *item);
status_t queue_get_front(queue_t *queue, void *item);


#endif