#include"Task_components.h"
//nei primi due non inizializzo self_ptr a null visto che
//se lo inizializzassi a this allora non potrei allocare staticamente la radice
//di un albero di task, e dovrei eliminarla manualmente visto che ci sarebbe sempre
//il self_ptr della suddetta anche quando ho finito di usarla

//rendendo leggermente inutile l'uso degli smart pointer
Task_component::Task_component()
:name(""),self_ptr(std::shared_ptr<Task_component>(nullptr)),
parent(std::shared_ptr<Task_composite>(nullptr)){}

Task_component::Task_component(std::string name)
:name(name),self_ptr(std::shared_ptr<Task_component>(nullptr)),
parent(std::shared_ptr<Task_composite>(nullptr)){}

Task_component::Task_component(std::shared_ptr<Task_composite> p)
:name(""),self_ptr(std::shared_ptr<Task_component>(this)){
  parent = p;
  parent->add(self_ptr);
}

Task_component::Task_component(std::string name, std::shared_ptr<Task_composite> p)
:name(name),self_ptr(std::shared_ptr<Task_component>(this)){
  parent = p;
  parent->add(self_ptr);
}

std::string Task_component::get_name(){
  return name;
}

void Task_component::set_name(std::string new_name){
  name = new_name;
}

std::shared_ptr<Task_composite> Task_component::get_parent(){
  return parent;
}

void Task_component::detach_parent(){
  parent->detach_child(self_ptr);
}

std::shared_ptr<Task_component> Task_component::get_self_ptr(){
  //lazy initialization, per permettere inizalizzazione statica dove necessaria
  if(!self_ptr){self_ptr = std::shared_ptr<Task_component>(this);}
  return self_ptr;
}

Task_component::~Task_component(){
  if(parent){
    //parent->detach_child(name);//if, altrimenti segmentation fault
    parent->get_children()->pop_back();
    //se viene sempre eliminata per prima l'ultima aggiunta
    //questa cosa dovrebbe equivalere a quella sopra
  }
  parent.reset();
  self_ptr.reset();
  std::cout<<"component destroyed\n";
}
