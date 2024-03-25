#ifndef TASK_LEAF_H
#define TASK_LEAF_H

#include<string>
#include "TaskComponent.hpp"

class TaskLeaf : public TaskComponent {
public:
    explicit TaskLeaf(std::string& name, std::string& description, Date& due_date):
        TaskComponent(name, description, due_date){}
    virtual void accept(TaskVisitor* v) override;
    virtual ~TaskLeaf() override;
};

#endif
