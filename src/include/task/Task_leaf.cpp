#include"Task_components.h"

Task_leaf::Task_leaf()
:Task_component(){}

Task_leaf::Task_leaf(std::string name)
:Task_component(name){}

Task_leaf::Task_leaf(std::shared_ptr<Task_composite> parent)
:Task_component(parent){}

Task_leaf::Task_leaf(std::string name, std::shared_ptr<Task_composite> parent)
:Task_component(name,parent){}

std::string Task_leaf::get_name(){
  return Task_component::get_name();
}

void Task_leaf::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

std::shared_ptr<Task_composite> Task_leaf::get_parent(){
  return Task_component::get_parent();
}

std::shared_ptr<Task_component> Task_leaf::get_self_ptr(){
  return Task_component::get_self_ptr();
}

Task_leaf::~Task_leaf(){
  std::cout<<"leaf "<<get_name()<<" destroyed\n";
}
