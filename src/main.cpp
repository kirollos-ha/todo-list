#include<iostream>

#include"include/task/Task_components.h"

int main(){
  Task_leaf task_leaf("we're no strangers to love");
  Task_composite task_composite("you know the rules and so do I");
  task_composite.add(task_leaf);
  task_composite.print_children();

  return 0;
}
