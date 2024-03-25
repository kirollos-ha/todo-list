#include"initializers.hpp"

std::shared_ptr<TaskLeaf>make_leaf(std::string name,
                                   std::string description,
                                   Date due_date,
                                   std::shared_ptr<TaskComposite> parent) {
    auto a = std::make_shared<TaskLeaf>(name, description, due_date);
    parent->add(a);
    return a;
}

std::shared_ptr<TaskComposite>make_root_composite(std::string name,
                                                  std::string description,
                                                  Date due_date) {
    return std::make_shared<TaskComposite>(name, description, due_date);
}

std::shared_ptr<TaskComposite>make_composite(std::string name,
                                             std::string description,
                                             Date due_date,
                                             std::shared_ptr<TaskComposite>parent) {
    auto a = std::make_shared<TaskComposite>(name, description, due_date);
    parent->add(a);
    return a;
}
