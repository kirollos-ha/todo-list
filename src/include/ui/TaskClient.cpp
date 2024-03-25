//da rinominare a controller per fare mvc

#include <memory>
#include <istream>
#include <queue>
#include <optional>

#include "TaskClient.hpp"
#include "../serializers/TaskFileParser.hpp"
#include "../serializers/TaskSerializer.hpp"
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

void TaskClient::add_leaf(std::string& name, std::string& description, Date& date) {
    make_leaf(name, description, date, curr_task);
}

void TaskClient::add_composite(std::string& name, std::string& description, Date& date) {
    make_composite(name, description, date, curr_task);
}

void TaskClient::remove_child(int index) {
    curr_task->detach_child(index);
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
        std::cerr<<"tc is "<< tc<<std::endl;
        std::cerr<<"it is not a composite, I cannot make it there"<<std::endl;
    }
}

std::vector<std::shared_ptr<TaskComponent>> TaskClient::curr_children_list() {
    return curr_task->get_children();
}

void TaskClient::push_child(std::shared_ptr<TaskComposite> child) {
    curr_task = child;
    curr_task_path.push_back(child);
}

const std::shared_ptr<TaskComponent> TaskClient::get_child(int index) const {
    return curr_task->get_child(index);
}

std::optional<std::shared_ptr<TaskComponent>> TaskClient::find_descendant(std::string &target_name) {
    return curr_task->find_descendant(target_name);
}

void TaskClient::write(std::ostream& os) {
    TaskSerializer ts(os);
    ts.visitComposite(curr_task_path[0].get());
    return;
}
