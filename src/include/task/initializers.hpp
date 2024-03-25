#ifndef TASK_INITIAILIZERS_H
#define TASK_INITIAILIZERS_H

#include<memory>

#include"TaskLeaf.hpp"
#include"TaskComposite.hpp"

#include"Date.hpp"

//per inizializzare direttamente da smart pointer quando serve
std::shared_ptr<TaskLeaf>make_leaf(std::string name,
                                   std::string description,
                                   Date due_date,
                                   std::shared_ptr<TaskComposite>parent);

std::shared_ptr<TaskComposite>make_root_composite(std::string name,
                                                  std::string description,
                                                  Date due_date);

std::shared_ptr<TaskComposite>make_composite(std::string name,
                                             std::string description,
                                             Date due_date,
                                             std::shared_ptr<TaskComposite>parent);

#endif
