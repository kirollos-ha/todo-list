#ifndef SEEKER_VISITOR_H
#define SEEKER_VISITOR_H

#include<stack>

#include "all.hpp"

// childseeker
// cerca tra i FIGLI del primo composite che visita, il composite stesso viene ignorato 
class ChildSeeker : public TaskVisitor {
public:
    ChildSeeker(const std::string& target):target(target) {}

    virtual void visitLeaf(TaskLeaf* l) override {
        if(is_good(l)) {
            found_it();
        }
    }

    virtual void visitComposite(TaskComposite* c) override {
        if(is_good(c)) {
            found_it();
        }
        for(auto ch : c->get_children()) {
            if(is_done())
                return;
            candidate=ch;
            ch->accept(this);
        }
    }

    std::shared_ptr<TaskComponent> get() {
        return res;
    }

    bool found_child() {
        return is_done();
    }

private:
    const std::string& target;
    std::shared_ptr<TaskComponent> candidate;
    std::shared_ptr<TaskComponent> res = std::shared_ptr<TaskComponent>(nullptr);

    bool is_good(TaskComponent* t) {
        return t->get_name().find(target) != std::string::npos;
    }

    bool is_done() {
        return res.get() != nullptr;
    }

    void found_it() {
        res = candidate;
    }
};

#endif
