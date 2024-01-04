#include "my_queue.h"

static int is_empty(queue_t *queue);
static int is_full(queue_t *queue);

status_t queue_create(queue_t *queue, int max_size) {
  status_t ret = queue_ok;
  if (queue == NULL)
    return queue_not_ok;
  else {
    queue->array = (void **)calloc(max_size, sizeof(void *));
    queue->front = -1;
    queue->reare = -1;
    queue->counter = 0;
    queue->max_size = max_size;
  }
  return ret;
}
status_t enqueue(queue_t *queue, void *item) {
  status_t ret = queue_ok;
  if (queue == NULL || item == NULL)
    ret = queue_not_ok;
  else {
    if (is_full(queue)) {
      ret = queue_full;
    } else {
      queue->reare++;
      if (queue->reare == queue->max_size)
        queue->reare = 0;
      queue->array[queue->reare] = item;
      if (is_empty(queue)) {
        queue->front++;
        queue->counter = 1;
      } else {
        queue->counter++;
      }
    }
  }

  return ret;
}

status_t dequeue(queue_t *queue, void *item) {
  status_t ret = queue_ok;
  if (queue == NULL || item == NULL)
    ret = queue_not_ok;
  else {
    if (is_empty(queue)) {
      ret = queue_empty;
    } else {
      item = queue->array[queue->front];
      queue->front++;
      if (queue->front == queue->max_size)
        queue->front = 0;
      if (queue->counter == 1) {
        queue->counter = 0;
        queue->front = -1;
        queue->reare = -1;
      }
      queue->counter--;
    }

    return ret;
  }
}

status_t destroy_queue(queue_t *queue) {
  status_t ret = queue_ok;
  if (queue == NULL) {
    return queue_not_ok;
  } else {
    free(queue->array);
  }

  return ret;
}

status_t queue_get_rear(queue_t *queue, void *item) {

  status_t ret = queue_ok;
  if (queue == NULL || item == NULL)
    ret = queue_not_ok;
  else {

    item = queue->array[queue->reare];
  }
  return ret;
}

status_t queue_get_front(queue_t *queue, void *item) {

  status_t ret = queue_ok;
  if (queue == NULL || item == NULL)
    ret = queue_not_ok;
  else {

    item = queue->array[queue->front];
  }
  return ret;
}

static int is_empty(queue_t *queue) {
  int res = 0;
  if (queue->counter == 0)
    res = 1;
  return res;
}
static int is_full(queue_t *queue) {
  return (queue->counter == queue->max_size);
}