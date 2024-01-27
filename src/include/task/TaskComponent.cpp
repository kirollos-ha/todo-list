#include"TaskComponent.hpp"

TaskComponent::TaskComponent() :name(""){};

TaskComponent::TaskComponent(std::string name) :name(name){}

std::string TaskComponent::get_name(){
  return name;
}

void TaskComponent::set_name(std::string new_name){
  name = new_name;
}

TaskComponent::~TaskComponent() = default;
