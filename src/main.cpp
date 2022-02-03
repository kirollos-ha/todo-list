#include<iostream>

#include"include/task/Task_components.h"

int main(){
  std::cout<<"hello, world!\n";

  //qualche chiamata nel main per vedere se non esplode nienete prima di aggiungere unit test
  Task_leaf task_leaf("we're no strangers to love");

  Task_composite task_composite("you know the rules and so do I");

  task_composite.add(task_leaf);

  task_composite.print_children();

  std::cout<<"nothing has blown up yet, good\n";

  return 0;
}
