#ifndef TASK_COUNTER_H
#define TASK_COUNTER_H

#include "TaskComponent.hpp"
#include "TaskLeaf.hpp"
#include "TaskComposite.hpp"

class TaskCounter : public TaskVisitor {
public:
    void visit_component(TaskComponent* tc) {
        total++;
        done+= tc->is_done();
        overdue+=tc->is_overdue();
    }
    void visitLeaf(TaskLeaf* l) override {
        visit_component(l);
    }
    void visitComposite(TaskComposite* c) override {
        visit_component(c);
        for(auto t : c->get_children()) {
            t->accept(this);
        }
    }
    int get_total() {
        return total;
    }
    int get_done() {
        return done;
    }
    int get_todo() {
        return total - done;
    }
    int get_overdue() {
        return overdue;
    }
private:
    int total = 0;
    int done = 0;
    int overdue = 0;
};

#endif
