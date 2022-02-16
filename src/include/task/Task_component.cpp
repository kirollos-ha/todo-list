#include"Task_components.h"

Task_component::Task_component()
:name(""){};

Task_component::Task_component(std::string name)
:name(name){}


std::string Task_component::get_name(){
  return name;
}

void Task_component::set_name(std::string new_name){
  name = new_name;
}

Task_component::~Task_component(){ }
