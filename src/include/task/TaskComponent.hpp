#ifndef TASK_COMPONENT_H
#define TASK_COMPONENT_H

#include<string>
#include<memory>

#include"Date.hpp"

class TaskComponent;
class TaskLeaf;
class TaskComposite;

class TaskVisitor {
public:

    virtual void visitLeaf(TaskLeaf*) = 0;
    virtual void visitComposite(TaskComposite*) = 0;
    virtual ~TaskVisitor() = default;
};

class TaskComponent {
public:
    explicit TaskComponent(std::string& name,
                           std::string& description,
                           Date& due_date);
    TaskComponent(TaskComponent&t)=delete;
    void operator=(TaskComponent&t)=delete;

    const std::string& get_name() const;
    const std::string& get_description() const;
    const Date& get_date() const;
    const bool is_done() const;

    // sono tutte funzioni che servono per fare edit nelle todo list
    // se voglio cambiare qualcosa di un elemento della lista
    void set_name(std::string& new_name);
    void set_description(std::string& new_description);
    void set_date(Date& new_date);
    void mark_done();

    virtual void accept(TaskVisitor* v) = 0;
    virtual ~TaskComponent();
    bool is_overdue() const;

private:
    // visto che sono mutable qui è meglio copiarle, la reference crea problemi
    // (grazie rust <3)
    std::string name;
    std::string description;
    Date due_date;
    bool done=false;
};

#endif
