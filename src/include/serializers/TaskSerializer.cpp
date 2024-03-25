#include <ostream>
#include "TaskSerializer.hpp"

TaskSerializer::TaskSerializer(std::ostream& os):os(os){}

void TaskSerializer::visitLeaf(TaskLeaf* leaf) {
    os<<"l"<<'\n'
      <<leaf->get_name()<<'\n'
      <<leaf->get_date().get_year()<<' '
      <<leaf->get_date().get_month()<<' '
      <<leaf->get_date().get_day()<<'\n'
      <<leaf->get_description()<<'\n';
}
void TaskSerializer::visitComposite(TaskComposite* comp) {
    os<<"cs"<<'\n'
      <<comp->get_name()<<'\n'
      <<comp->get_date().get_year()<<' '
      <<comp->get_date().get_month()<<' '
      <<comp->get_date().get_day()<<'\n'
      <<comp->get_description()<<'\n';
    for(auto c : comp->get_children()) {
        c->accept(this);
    }
    os<<"ce\n";
}

TaskSerializer::~TaskSerializer() = default;
