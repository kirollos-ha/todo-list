#ifndef TASK_CLIENT_H
#define TASK_CLIENT_H

#include <istream>
#include <memory>
#include <iostream>
#include <vector>

#include "../task/all.hpp"

/* La navigazione dell'albero dei task imita qui la navigazione di una cartella
 * di file e cartelle, con path e subtask che possono contenere subtask
 * perchè sì
 */
class TaskClient {
public:
    TaskClient(std::shared_ptr<TaskComposite>);
    TaskClient(std::istream& is);

    void add_leaf(std::string);
    void add_composite(std::string);

    void remove_child(int index);
    void remove_child(std::string);

    void rename_child(int index, std::string new_name);
    void go_up();
    void go_to_child(int index);
    void go_to_child(std::string target_name);
    std::vector<std::shared_ptr<TaskComponent>> curr_children_list();

    std::shared_ptr<TaskComponent> get_child(int index);
    std::shared_ptr<TaskComponent> find_child(std::string target_name);

    std::vector<std::shared_ptr<TaskComposite>> get_path();
    void write(std::ostream& os);

    ~TaskClient() = default;
private:
    std::shared_ptr<TaskComposite> curr_task;
    std::vector<std::shared_ptr<TaskComposite>> curr_task_path;

    void push_child(std::shared_ptr<TaskComposite>);
};

#endif
