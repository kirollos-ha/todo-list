#ifndef TASK_COMPOSITE_H
#define TASK_COMPOSITE_H

#include<string>
#include<memory>
#include<vector>
#include <optional>
#include "TaskComponent.hpp"

class TaskComposite : public TaskComponent {
public:
    explicit TaskComposite(std::string& name, std::string& description, Date& due_date):
        TaskComponent(name, description, due_date){}

    virtual void accept(TaskVisitor* v) override ;

    void add(std::shared_ptr<TaskComponent> new_child);

    void detach_child(int index);
    void detach_child(std::shared_ptr<TaskComponent>);

    const std::vector<std::shared_ptr<TaskComponent>> get_children() const;
    std::shared_ptr<TaskComponent> get_child(int index) const;

    std::optional<std::shared_ptr<TaskComponent>> find_descendant(std::string& target);

    virtual ~TaskComposite();
private:
    std::vector<std::shared_ptr<TaskComponent>>children;
};

#endif
