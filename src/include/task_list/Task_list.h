#ifndef TASK_LIST_H
#define TASK_LIST_H
//std::list chiama il distruttore del pointer eliminato e

#include"../task"
#include<memory>

class Task_list_node{
public:
  Task_list_node()
private:
  std::shared_ptr<Task_component> val;
  std::unique_ptr<Task_list_node> next;
};

class Task_list{
public:
  Task_list();//non serve inizializzarla con valori
  void add(std::shared_ptr)
private:
  Task_list_node head;//head.next = primo coso della lista
};

#endif
