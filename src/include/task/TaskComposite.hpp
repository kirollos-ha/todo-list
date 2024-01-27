#ifndef TASK_COMPOSITE_H
#define TASK_COMPOSITE_H

#include<string>
#include<memory>
#include<vector>
#include "TaskComponent.hpp"

class TaskComposite : public TaskComponent {
public:
    TaskComposite();
    TaskComposite(std::string name);

    virtual std::string get_name() override;
    virtual void set_name(std::string new_name) override;
    virtual void accept(TaskVisitor* v) override ;

    void add(std::shared_ptr<TaskComponent> new_child);

    void detach_child(int index);
    void detach_child(std::string target_name);
    void detach_child(std::shared_ptr<TaskComponent>);

    std::vector<std::shared_ptr<TaskComponent>> get_children();

    std::shared_ptr<TaskComponent> find_child(std::string name);
    std::shared_ptr<TaskComponent> get_child(int index);

    virtual ~TaskComposite();
private:
    std::vector<std::shared_ptr<TaskComponent>>children;
};

#endif
