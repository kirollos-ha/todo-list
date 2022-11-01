#include"Task_components.h"
//hic sunt std::smart_puntatores

std::shared_ptr<Task_leaf>make_leaf(){
  return std::make_shared<Task_leaf>();
}

std::shared_ptr<Task_leaf>make_leaf(std::string name){
  return std::make_shared<Task_leaf>(name);
}

std::shared_ptr<Task_leaf>make_leaf(std::shared_ptr<Task_composite> parent){
  auto a = std::make_shared<Task_leaf>();
  parent->add(a);
  return a;
}

std::shared_ptr<Task_leaf>make_leaf(std::string name,
  std::shared_ptr<Task_composite> parent ){
  auto a = std::make_shared<Task_leaf>(name);
  parent->add(a);
  return a;
}


std::shared_ptr<Task_composite>make_composite(){
  return std::make_shared<Task_composite>();
}

std::shared_ptr<Task_composite>make_composite(std::string name){
  return std::make_shared<Task_composite>(name);
}

std::shared_ptr<Task_composite>make_composite
(std::shared_ptr<Task_composite> parent){
  auto a = std::make_shared<Task_composite>();
  parent->add(a);
  return a;
}

std::shared_ptr<Task_composite>make_composite(std::string name,
  std::shared_ptr<Task_composite> parent ){
  auto a = std::make_shared<Task_composite>(name);
  parent->add(a);
  return a;
}
