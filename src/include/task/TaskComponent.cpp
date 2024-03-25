#include"TaskComponent.hpp"

TaskComponent::TaskComponent(std::string& name,
                             std::string& description,
                             Date& due_date)
    :name(name), description(description), due_date(due_date){}
     

const std::string& TaskComponent::get_name() const {
    return name;
}

const std::string& TaskComponent::get_description() const {
    return description;
}

const Date& TaskComponent::get_date() const {
    return due_date;
}

const bool TaskComponent::is_done() const {
    return done;
}

void TaskComponent::set_name(std::string& new_name){
    name = new_name;
}

void TaskComponent::set_description(std::string& new_description) {
    description = new_description;
}

void TaskComponent::set_date(Date& new_date) {
    due_date = new_date;
}

void TaskComponent::mark_done() {
    done = true;
}

bool TaskComponent::is_overdue() const {
    return (!done)
        && (Date::get_current().is_past(due_date));
}

TaskComponent::~TaskComponent() = default;
