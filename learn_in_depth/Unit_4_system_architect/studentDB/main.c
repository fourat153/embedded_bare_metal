#include "StudentDB.h"
#include <stdio.h>

int main() {

  printf("---------------welcome--------------\n");
  printf("from those option choose one ....\n");
  while (1) {
    int choice = 0;
    scanf("%d",&choice);
    while(1){
    if(choice < 1 || choice > 9){
       printf("plesae enter a valid option\n");
       scanf("%d",&choice);
    }
    else
    {
      break;
    }
    }
    switch (choice) {
    case 1:
      printf("please enter student data ...\n");
      add_student();
      break;
    case 2:
      printf("please enter a student ID...\n");
      int studen_id = 0;
      scanf("%d", &studen_id);
      delete_student(studen_id);
      break;

    case 3:
      printf("all students data...\n");
      print_all_student();
      break;
    case 4:
      add_student();
      printf("all students data deleted  ...\n");
      break;
    case 5:
      printf("please enter a student number...\n");
      int studen_n = 0;
      scanf("%d" , &studen_n);
      find_student_node(studen_n);
      break;

    case 6:
      printf("count student student data ...\n");
      list_students_count_iterative();
      break;

    case 7:
      printf("count student student data ...\n");
      list_students_count_recursive();
      break;
    case 8:
      printf("the middele is \n");
      list_get_middle_student();
      break;

    case 9:
      printf("reverse student data ...\n");
      list_reverse_students();
      break;
    case 10:
      printf("exit...\n");
      break;
    }
  }
}