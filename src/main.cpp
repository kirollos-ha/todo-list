#include<iostream>

#include"include/task/Task_components.h"

int main(){
  std::cout<<"this was printed before the scope!\n";
  if(true){
    std::cout<<"this was printed at the beginning of the \"if\" statement\n\n";
    auto father = make_composite("we're no strangers to love");
    auto child = make_leaf("you know the rules, and so do I");
    auto other_child = make_composite("a full commitment's what I'm thinking of");
    auto grandchild = make_leaf("you wouldn't get this from any other guy");
    std::cout<<"this was printed after the definitions, and declarations!\n\n";
    father->add(child);
    father->add(other_child);
    other_child->add(grandchild);
    father->print_children();
    other_child->print_children();
    std::cout<<"this was printed at the end of the \"if\" statement\n\n";
  }
  std::cout<<"this was printed after the scope!\n";

  return 0;
}
