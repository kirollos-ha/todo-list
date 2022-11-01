#include"Task_components.h"

Task_composite::Task_composite()
:Task_component(){}

Task_composite::Task_composite(std::string name)
:Task_component(name){}


std::string Task_composite::get_name(){
  return Task_component::get_name();
}

void Task_composite::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

//poi da vedere se andrebbe meglio con uno unique_ptr
void Task_composite::add(std::shared_ptr<Task_component> new_child){
  children.push_back(new_child);
}

void Task_composite::print_children(){
  for(auto p:children){
    std::cout<<p->get_name()<<'\n';
  }
}

void Task_composite::detach_child(std::string target_name){
  for(auto it=children.begin();it!=children.end();it++){
    if((*it)->get_name()==target_name){
      children.erase(it);
      return;
    }
  }
}

void Task_composite::detach_child(std::shared_ptr<Task_component> target){
  for(auto it=children.begin();it!=children.end();it++){
    if((*it).get()==target.get()){
      children.erase(it);
      return;
    }
  }
}

std::list<std::shared_ptr<Task_component>>* Task_composite::get_children(){
  return (&children);
}

Task_composite::~Task_composite(){ }
