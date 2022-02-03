#include"Task_components.h"

//TODO fai che il costruttore con padre metta il nodo tra i figli del padre
Task_component::Task_component()
:name(""),parent(std::shared_ptr<Task_composite>(nullptr)){}

Task_component::Task_component(std::string name)
:name(name),parent(std::shared_ptr<Task_composite>(nullptr)){}

Task_component::Task_component(Task_composite& parent)
:name(""),parent(std::shared_ptr<Task_composite>(&parent)){}

Task_component::Task_component(std::string name, Task_composite& parent)
:name(name),parent(std::shared_ptr<Task_composite>(&parent)){}

void Task_component::remove(){
  parent->release_child(name);
  //TODO va comunque deallocato restano gli shared_ptr dei figli
}

std::string Task_component::get_name(){
  return name;
}

void Task_component::set_name(std::string new_name){
  name = new_name;
}



Task_leaf::Task_leaf()
:Task_component(){}

Task_leaf::Task_leaf(std::string name)
:Task_component(name){}

Task_leaf::Task_leaf(Task_composite& parent)
:Task_component(parent){}

Task_leaf::Task_leaf(std::string name, Task_composite& parent)
:Task_component(name,parent){}

//controlla poi di aver usato la sintassi giusta
void Task_leaf::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

void Task_leaf::remove(){
  Task_component::remove();
}



Task_composite::Task_composite()
:Task_component(){}

Task_composite::Task_composite(std::string name)
:Task_component(name){}

Task_composite::Task_composite(Task_composite& parent)
:Task_component(parent){}

Task_composite::Task_composite(std::string name, Task_composite& parent)
:Task_component(name,parent){}

void Task_composite::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

void Task_composite::remove(){
  Task_component::remove();
}

void Task_composite::add(Task_component& new_child){
  children.push_back(std::shared_ptr<Task_component>(&new_child));
}

void Task_composite::print_children(){
  for(auto p:children){
    std::cout<<p->get_name()<<'\n';
  }
}

void Task_composite::release_child(std::string target_name){
  //non passata come reference per permettere uso di rvalue costanti nei test
  for(auto it=children.begin();it!=children.end();){
    //TODO flusso di controllo troppo complicato, semplificalo
    if((*it)->get_name()==target_name){
      auto to_delete = it;
      it++;
      children.erase(to_delete);
      return;
    }
    else{
      it++;
    }
  }
}
