#include"initializers.hpp"

std::shared_ptr<TaskLeaf>make_leaf(){
  return std::make_shared<TaskLeaf>();
}

std::shared_ptr<TaskLeaf>make_leaf(std::string name){
  return std::make_shared<TaskLeaf>(name);
}

std::shared_ptr<TaskLeaf>make_leaf(std::shared_ptr<TaskComposite> parent){
  auto a = std::make_shared<TaskLeaf>();
  parent->add(a);
  return a;
}

std::shared_ptr<TaskLeaf>make_leaf(std::string name,
  std::shared_ptr<TaskComposite> parent ){
  auto a = std::make_shared<TaskLeaf>(name);
  parent->add(a);
  return a;
}


std::shared_ptr<TaskComposite>make_composite(){
  return std::make_shared<TaskComposite>();
}

std::shared_ptr<TaskComposite>make_composite(std::string name){
  return std::make_shared<TaskComposite>(name);
}

std::shared_ptr<TaskComposite>make_composite
(std::shared_ptr<TaskComposite> parent){
  auto a = std::make_shared<TaskComposite>();
  parent->add(a);
  return a;
}

std::shared_ptr<TaskComposite>make_composite(std::string name,
  std::shared_ptr<TaskComposite> parent ){
  auto a = std::make_shared<TaskComposite>(name);
  parent->add(a);
  return a;
}
