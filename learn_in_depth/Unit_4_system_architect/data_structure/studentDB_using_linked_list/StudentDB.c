#include "StudentDB.h"
#include <stdio.h>
#include <stdlib.h>
student_t *head = NULL;
student_t *tail = NULL;
static student_t *ptr;

int counter = 0;
static void add_student_info(student_t *student) {

  printf("enter student  name\n");
  fflush(stdin);
  gets(student->name);
  printf("enter student  ID \n");
  scanf("%d", &student->ID);
  printf("enter student  height\n");
  scanf("%d", &student->height);
}
status_t add_student() {
  status_t ret = DB_ok;
  student_t *student_c;
  student_c = (student_t *)malloc(sizeof(student_t));
  if (student_c == NULL) {
    ret = DB_not_ok;
    return ret;
  }
  counter++;
  if (head == NULL) {
    head = student_c;
    student_c->next = NULL;
    tail = student_c;
    
    add_student_info(student_c);

  } else {
    student_t *tem = head;
    while (tem) {
      if (tem->next == NULL) {
        tem->next = student_c;
        student_c->next = NULL;
        tail = student_c;
        add_student_info(student_c);
        break;
      }

      tem = tem->next;
    }
  }

  return ret;
}
status_t delete_student(int student_ID) {
  status_t ret = DB_ok;
  student_t *ptrstudent;
  student_t *ptrstudent2;
  ptrstudent = head;
  ptrstudent2 = head;
  while (ptrstudent) {
    ptrstudent2 = ptrstudent2->next;
    if (ptrstudent->ID == student_ID) {
      head = ptrstudent->next;
      break;
    } else if (ptrstudent2->next == NULL) {

      if (ptrstudent2->ID == student_ID) {
        ptrstudent->next = NULL;
        tail = ptrstudent;
      }
    } else if (ptrstudent2->ID == student_ID) {
      ptrstudent->next = ptrstudent2->next;
    }
    ptrstudent = ptrstudent->next;
    counter--;
  }
}

status_t print_all_student() {
  status_t ret = DB_ok;
  student_t *ptr = head;
  if (ptr == NULL) {
    ret = DB_not_ok;
    return ret;
  }
  while (ptr) {
    printf("%s\n", ptr->name);
    ptr = ptr->next;
  }
  return ret;
}
status_t delete_all_students() {
  status_t ret = DB_ok;
  student_t *current_ptr = head;
  if (current_ptr == NULL) {
    ret = DB_not_ok;
    return ret;
  }

  while (current_ptr) {
    student_t *temp = current_ptr;
    current_ptr = current_ptr->next;
    free(temp);
  }
  head = NULL;
  tail =NULL;
  counter = 0;
  return ret;
}

status_t find_student_node(int number) {
  status_t ret = DB_ok;
  student_t *ptr = head;
  if (number > counter || ptr ==NULL) {
    ret = DB_not_ok;
  }
  while (number--) {
    ptr = ptr->next;
  }
  printf("student name %s\n", ptr->name);
  printf("student ID   %d\n", ptr->ID);
  printf("student age  %d\n", ptr->height);
  return ret;
}
int list_students_count_iterative(void) {
  status_t ret = DB_ok;
  int count = 0;
  student_t *ptr = head;
  if (ptr == NULL) {
    ret = DB_not_ok;
    return ret;
  }
  while (ptr) {
    count++;
    ptr = ptr->next;
  }
  return count;
}

int list_students_count_recursive() {
  if (ptr == NULL) {
    ptr = head;
  }
  if (ptr->next == NULL)
    return 1;
  else {
    ptr = ptr->next;
    return 1 + list_students_count_recursive();
  }
}

/**
 * @brief 
 * 
 */
void list_get_middle_student(void)
{
   int target = counter/2 + 1;
   find_student_node(target);
}

void list_reverse_students(void)
{
  student_t  * current =head ; 
  student_t * previous= NULL ; 
  student_t * next =NULL ; 
  tail = current;
  while (current)
  {
    next = current->next; 
    current->next = previous;
    previous = current ; 
    current = next;
  }
  head = previous;
  
}
