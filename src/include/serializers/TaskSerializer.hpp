#ifndef TASK_SERIALIZER_H
#define TASK_SERIALIZER_H

#include<ostream>

#include "../task/TaskComponent.hpp"
#include "../task/TaskLeaf.hpp"
#include "../task/TaskComposite.hpp"

class TaskSerializer : public TaskVisitor {
public:
    TaskSerializer(std::ostream& os);
    virtual void visitLeaf(TaskLeaf*) override;
    virtual void visitComposite(TaskComposite*) override;
    virtual ~TaskSerializer();
private:
    std::ostream &os;
};

#endif
