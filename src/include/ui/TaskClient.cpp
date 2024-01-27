//da rinominare a controller per fare mvc

#include <memory>
#include <istream>

#include "TaskClient.hpp"
#include "../serializers/TaskSerializer.hpp"
#include "../serializers/TaskFileParser.hpp"
#include "../task/initializers.hpp"


TaskClient::TaskClient(std::shared_ptr<TaskComposite> ptr) {
    curr_task = ptr;
    curr_task_path = std::vector<std::shared_ptr<TaskComposite>>();
    curr_task_path.push_back(curr_task);
}

TaskClient::TaskClient(std::istream& is) {
    TaskFileParser fp;
    curr_task = fp.read(is);
    curr_task_path = std::vector<std::shared_ptr<TaskComposite>>();
    curr_task_path.push_back(curr_task);
}

void TaskClient::add_leaf(std::string leaf_name) {
    curr_task->add(make_leaf(leaf_name));
}

void TaskClient::add_composite(std::string composite_name) {
    curr_task->add(make_composite(composite_name));
}

void TaskClient::remove_child(int index) {
    curr_task->detach_child(index);
}

void TaskClient::remove_child(std::string target_name) {
    curr_task->detach_child(target_name);
}

void TaskClient::go_up() {
    if(curr_task_path.size() > 1) {
        curr_task_path.pop_back();
        curr_task=curr_task_path.back();
    }
}

void TaskClient::go_to_child(int index) {
    std::shared_ptr<TaskComponent> child = curr_task->get_child(index);
    if(auto tc = std::dynamic_pointer_cast<TaskComposite>(child)) {
        push_child(tc);
    }
    else {
        std::cout<<"tc is "<< tc<<std::endl;
        std::cout<<"it is not a composite, I cannot make it there"<<std::endl;
    }
}

void TaskClient::go_to_child(std::string target_name) {
    std::shared_ptr<TaskComponent> child = curr_task->find_child(target_name);
    if(auto tc = std::dynamic_pointer_cast<TaskComposite>(child)) {
        push_child(tc);
    }
    else {
        std::cout<<"tc is "<< tc<<std::endl;
        std::cout<<"it is not a composite, I cannot make it there"<<std::endl;
    }
}

std::vector<std::shared_ptr<TaskComponent>> TaskClient::curr_children_list() {
    return curr_task->get_children();
}

std::vector<std::shared_ptr<TaskComposite>> TaskClient::get_path() {
    return curr_task_path;
}

void TaskClient::push_child(std::shared_ptr<TaskComposite> child) {
    curr_task = child;
    curr_task_path.push_back(child);
}

std::shared_ptr<TaskComponent> TaskClient::get_child(int index) {
    return curr_task->get_child(index);
}

std::shared_ptr<TaskComponent> TaskClient::find_child(std::string target_name) {
    return curr_task->find_child(target_name);
}

void TaskClient::write(std::ostream& os) {
    TaskSerializer ts(os);
    ts.visitComposite(curr_task_path[0].get());
}
