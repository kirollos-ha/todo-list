#ifndef TASK_COMPONENT_H
#define TASK_COMPONENT_H

#include<string>
#include<memory>

class TaskComponent;
class TaskLeaf;
class TaskComposite;

class TaskVisitor {
public:
    virtual void visitLeaf(TaskLeaf*) = 0;
    virtual void visitComposite(TaskComposite*) = 0;
    virtual ~TaskVisitor() = default;
};

class TaskComponent{
public:
    TaskComponent();
    explicit TaskComponent(std::string name);

    virtual std::string get_name();
    virtual void set_name(std::string new_name);
    virtual void accept(TaskVisitor* v) = 0;

    virtual ~TaskComponent();

private:
    std::string name;
};

#endif
