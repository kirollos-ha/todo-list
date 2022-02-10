#include"Task_components.h"

Task_component::Task_component()
:name(""),parent(std::shared_ptr<Task_composite>(nullptr)){}

Task_component::Task_component(std::string name)
:name(name),parent(std::shared_ptr<Task_composite>(nullptr)){}

Task_component::Task_component(Task_composite& parent)
:name(""),parent(std::shared_ptr<Task_composite>(&parent)){
  parent.add(std::shared_ptr<Task_component>(this));
}

Task_component::Task_component(std::string name, Task_composite& parent)
:name(name),parent(std::shared_ptr<Task_composite>(&parent)){
  parent.add(std::shared_ptr<Task_component>(this));
}

void Task_component::remove(){
  parent->release_child(name);
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


Task_leaf::Task_leaf()
:Task_component(){}

Task_leaf::Task_leaf(std::string name)
:Task_component(name){}

Task_leaf::Task_leaf(Task_composite& parent)
:Task_component(parent){}

Task_leaf::Task_leaf(std::string name, Task_composite& parent)
:Task_component(name,parent){}

void Task_leaf::remove(){
  Task_component::remove();
}

std::string Task_leaf::get_name(){
  return Task_component::get_name();
}

void Task_leaf::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

std::shared_ptr<Task_composite> Task_leaf::get_parent(){
  return Task_component::get_parent();
}


Task_composite::Task_composite()
:Task_component(){}

Task_composite::Task_composite(std::string name)
:Task_component(name){}

Task_composite::Task_composite(Task_composite& parent)
:Task_component(parent){}

Task_composite::Task_composite(std::string name, Task_composite& parent)
:Task_component(name,parent){}

void Task_composite::remove(){
  Task_component::remove();
}

std::string Task_composite::get_name(){
  return Task_component::get_name();
}

void Task_composite::set_name(std::string new_name){
  Task_component::set_name(new_name);
}

std::shared_ptr<Task_composite> Task_composite::get_parent(){
  return Task_component::get_parent();
}

void Task_composite::add(std::shared_ptr<Task_component>new_child){
  children.push_back(new_child);
}

void Task_composite::print_children(){
  for(auto p:children){
    std::cout<<p->get_name()<<'\n';
  }
}

void Task_composite::release_child(std::string target_name){
  //non passata come reference per permettere uso di rvalue costanti nei test
  for(auto it=children.begin();it!=children.end();it++){
    if((*it)->get_name()==target_name){
      children.erase(it);
      return;
    }
  }
}

std::shared_ptr<std::list<std::shared_ptr<Task_component>>> Task_composite::get_children(){
  return static_cast<std::shared_ptr<std::list<std::shared_ptr<Task_component>>>>(&children);
}

//hic sunt std::smart_puntatores

std::shared_ptr<Task_leaf>make_leaf(){
  return std::make_shared<Task_leaf>();
}
std::shared_ptr<Task_leaf>make_leaf(std::string name){
  return std::make_shared<Task_leaf>(name);
}
std::shared_ptr<Task_leaf>make_leaf(std::shared_ptr<Task_composite>parent){
  return std::make_shared<Task_leaf>(*(parent));
}
std::shared_ptr<Task_leaf>make_leaf(std::string name,
  std::shared_ptr<Task_composite>parent){
  return std::make_shared<Task_leaf>(name,*(parent));
}

std::shared_ptr<Task_composite>make_composite(){
  return std::make_shared<Task_composite>();
}
std::shared_ptr<Task_composite>make_composite(std::string name){
  return std::make_shared<Task_composite>(name);
}
std::shared_ptr<Task_composite>make_composite(std::shared_ptr<Task_composite>parent){
  return std::make_shared<Task_composite>(*(parent));
}
std::shared_ptr<Task_composite>make_composite(std::string name,
  std::shared_ptr<Task_composite>parent){
  return std::make_shared<Task_composite>(name,*(parent));
}
