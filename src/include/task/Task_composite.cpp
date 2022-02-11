#include"Task_components.h"

Task_composite::Task_composite()
:Task_component(){}

Task_composite::Task_composite(std::string name)
:Task_component(name){}

Task_composite::Task_composite(std::shared_ptr<Task_composite> parent)
:Task_component(parent){}

Task_composite::Task_composite(std::string name, std::shared_ptr<Task_composite> parent)
:Task_component(name,parent){}

std::string Task_composite::get_name(){
  return Task_component::get_name();
  std::cout<<"I am clearing this list!\n";
}


void Task_composite::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

std::shared_ptr<Task_composite> Task_composite::get_parent(){
  return Task_component::get_parent();
}

std::shared_ptr<Task_component> Task_composite::get_self_ptr(){
  return Task_component::get_self_ptr();
}

void Task_composite::add(std::shared_ptr<Task_component>new_child){
  children.push_back(new_child);
}

void Task_composite::print_children(){
  for(auto p:children){
    std::cout<<p->get_name()<<'\n';
  }
}

void Task_composite::detach_child(std::string target_name){
  //non passata come reference per permettere uso di rvalue costanti nei test
  for(auto it=children.begin();it!=children.end();it++){
    if((*it)->get_name()==target_name){
      children.erase(it);
      return;
    }
  }
}

void Task_composite::detach_child(std::shared_ptr<Task_component> target){
  for(auto it=children.begin();it!=children.end();it++){
    std::cout<<"I'm motivated! I'm iterating!\n";
    if((*it).get()==target.get()){//dereference allo stesso pointer = GOOD
      std::cout<<"motherfucker was found, now destroy the target!\n";
      children.erase(it);
      std::cout<<"target erased, it was SIIIIIIIICK, DUDE!!!!!!\n";
      return;
      //a togliere il legame dalla parte del figlio ci pensa il figlio
    }
  }
}

std::shared_ptr<std::list<std::shared_ptr<Task_component>>> Task_composite::get_children(){
  return static_cast<std::shared_ptr<std::list<std::shared_ptr<Task_component>>>>(&children);
}

Task_composite::~Task_composite(){
  children.clear();
  //e coi distruttori dei figli equivale a rm -rf this (metaforicamente);
  std::cout<<"composite "<<get_name()<<" destroyed\n";
}
