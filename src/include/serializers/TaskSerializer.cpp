#include <ostream>
#include "TaskSerializer.hpp"

TaskSerializer::TaskSerializer(std::ostream& os):os(os){}

void TaskSerializer::visitLeaf(TaskLeaf* leaf) {
    os<<"l "<<leaf->get_name()<<'\n';
}
void TaskSerializer::visitComposite(TaskComposite* comp) {
    os<<"cs "<<comp->get_name()<<'\n';
    for(auto c : comp->get_children()) {
        c->accept(this);
    }
    os<<"ce\n";
}

TaskSerializer::~TaskSerializer() = default;
