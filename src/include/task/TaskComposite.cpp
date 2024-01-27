#include"TaskComposite.hpp"

TaskComposite::TaskComposite()
    :TaskComponent(){}

TaskComposite::TaskComposite(std::string name)
    :TaskComponent(name){}


std::string TaskComposite::get_name(){
    return TaskComponent::get_name();
}

void TaskComposite::set_name(std::string new_name){
    TaskComponent::set_name(new_name);
}

void TaskComposite::accept(TaskVisitor* v) {
    v->visitComposite(this);
}


//poi da vedere se andrebbe meglio con uno unique_ptr
void TaskComposite::add(std::shared_ptr<TaskComponent> new_child){
    children.push_back(new_child);
}

void TaskComposite::detach_child(int index) {
    children.erase(children.begin() + index);
}

void TaskComposite::detach_child(std::string target_name){
    for(auto it=children.begin();it!=children.end();it++){
        if((*it)->get_name()==target_name){
            children.erase(it);
            return;
        }
    }
}

void TaskComposite::detach_child(std::shared_ptr<TaskComponent> target){
    for(auto it=children.begin();it!=children.end();it++){
        if((*it).get()==target.get()){
            children.erase(it);
            return;
        }
    }
}

std::vector<std::shared_ptr<TaskComponent>> TaskComposite::get_children(){
    return children;
}

std::shared_ptr<TaskComponent> TaskComposite::find_child(std::string name) {
    for(std::shared_ptr<TaskComponent> t_ptr : children) {
        if(t_ptr->get_name() == name)
            return t_ptr;
    }
    return std::shared_ptr<TaskComponent>(nullptr);
}
std::shared_ptr<TaskComponent> TaskComposite::get_child(int index) {
    return children[index];
}

TaskComposite::~TaskComposite() = default;
