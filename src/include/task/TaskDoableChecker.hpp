#ifndef TASK_DOABLE_CHECKER_H
#define TASK_DOABLE_CHECKER_H

#include "TaskComponent.hpp"
#include "TaskLeaf.hpp"
#include "TaskComposite.hpp"

class TaskDoableChecker : public TaskVisitor {
public:
    bool is_doable(TaskComponent *tc) {
        found_not_doable = false;
        tc->accept(this);
        return !(found_not_doable);
    }

    void visitLeaf(TaskLeaf* tl) override {
        return; //leaves are alwyas doable
    }

    void visitComposite(TaskComposite* tc) override {
        for(auto child : tc->get_children()) {
            if(!(child->is_done())) {
                found_not_doable = true;
                return;
            }
            else
                child->accept(this);
        }
    }

private:
    bool found_not_doable = false;
};

#endif
