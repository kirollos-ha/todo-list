#include "TaskLeaf.hpp"

TaskLeaf::TaskLeaf() :TaskComponent(){}

TaskLeaf::TaskLeaf(std::string name) :TaskComponent(name){}

std::string TaskLeaf::get_name(){
    return TaskComponent::get_name();
}

void TaskLeaf::set_name(std::string new_name){
    TaskComponent::set_name(new_name);
}

void TaskLeaf::accept(TaskVisitor* v) {
    v->visitLeaf(this);
}

TaskLeaf::~TaskLeaf(){ }
