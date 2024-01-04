#ifndef __STUDENTDB__H
#define __STUDENTDB__H

#include <stdlib.h>

typedef struct {
  char name[20];
  int ID;
  int height;
  struct student_t *next;
} student_t;

typedef enum {
  DB_ok,
  DB_not_ok,

} status_t;

status_t add_student();
status_t delete_student(int student_ID);
status_t print_all_student();
status_t delete_all_students();
status_t find_student_node(int number);
int list_students_count_iterative(void);
int list_students_count_recursive();
void list_get_middle_student(void);
void list_reverse_students(void);

#endif