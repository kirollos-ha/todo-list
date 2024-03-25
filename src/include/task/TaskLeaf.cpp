#include "TaskLeaf.hpp"

void TaskLeaf::accept(TaskVisitor* v) {
    v->visitLeaf(this);
}

TaskLeaf::~TaskLeaf(){ }
