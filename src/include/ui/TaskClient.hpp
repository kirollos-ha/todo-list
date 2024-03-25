#ifndef TASK_CLIENT_H
#define TASK_CLIENT_H

#include <istream>
#include <memory>
#include <iostream>
#include <vector>
#include <optional>

#include "../task/TaskComponent.hpp"
#include "../task/TaskLeaf.hpp"
#include "../task/TaskComposite.hpp"
#include "../task/initializers.hpp"
#include "../task/Date.hpp"


// navigazoine task imita navigazione directory
class TaskClient {
public:
    TaskClient(std::shared_ptr<TaskComposite>);
    TaskClient(std::istream& is);

    // poi metti queste a reference se ha funzionato 
    void add_leaf(std::string& name, std::string& description, Date& date);
    void add_composite(std::string& name, std::string& description, Date& date);

    void remove_child(int index);
    void rename_child(int index, std::string& new_name);
    void go_up();
    void go_to_child(int index);
    std::vector<std::shared_ptr<TaskComponent>> curr_children_list();

    const int curr_n_children() const {
        return curr_task->get_children().size();
    }

    const std::shared_ptr<TaskComponent> get_child(int index) const;
    std::optional<std::shared_ptr<TaskComponent>> find_descendant(std::string& target_name);

    void write(std::ostream& os);

    ~TaskClient() = default;
private:
    std::shared_ptr<TaskComposite> curr_task;
    std::vector<std::shared_ptr<TaskComposite>> curr_task_path;

    void push_child(std::shared_ptr<TaskComposite>);
};

#endif
