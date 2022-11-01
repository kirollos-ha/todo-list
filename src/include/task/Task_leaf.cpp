#include"Task_components.h"

Task_leaf::Task_leaf()
:Task_component(){}

Task_leaf::Task_leaf(std::string name)
:Task_component(name){}

std::string Task_leaf::get_name(){
  return Task_component::get_name();
}

void Task_leaf::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

Task_leaf::~Task_leaf(){ }
