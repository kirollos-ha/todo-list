#ifndef TASK_LEAF_H
#define TASK_LEAF_H

#include<string>
#include "TaskComponent.hpp"

class TaskLeaf : public TaskComponent {
public:
    TaskLeaf();
    explicit TaskLeaf(std::string name);

    virtual std::string get_name() override;
    virtual void set_name(std::string new_name) override;
    virtual void accept(TaskVisitor* v) override;

    virtual ~TaskLeaf();
};

#endif
