#include"TaskComposite.hpp"
#include "TaskComponent.hpp"
#include "ChildSeeker.hpp"
#include <memory>

void TaskComposite::accept(TaskVisitor* v) {
    v->visitComposite(this);
}

//poi da vedere se andrebbe meglio con uno unique_ptr
void TaskComposite::add(std::shared_ptr<TaskComponent> new_child) {
    children.push_back(new_child);
}

void TaskComposite::detach_child(int index) {
    children.erase(children.begin() + index);
}

const std::vector<std::shared_ptr<TaskComponent>> TaskComposite::get_children() const {
    return children;
}

std::shared_ptr<TaskComponent> TaskComposite::get_child(int index) const {
    return children[index];
}

std::optional<std::shared_ptr<TaskComponent>> TaskComposite::find_descendant(std::string& target) {
    ChildSeeker ch(target);
    accept(&ch);
    if(ch.found_child())
        return std::optional<std::shared_ptr<TaskComponent>>(ch.get());
    else
        return std::optional<std::shared_ptr<TaskComponent>>();
        
}

TaskComposite::~TaskComposite() = default;
