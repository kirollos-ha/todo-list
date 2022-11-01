#ifndef TASK_CLIENT_H
#define TASK_CLIENT_H

#include <memory>
#include <iostream>
#include <stack>

#include "../task/Task_components.h"

/* La navigazione dell'albero dei task imita qui la navigazione di una cartella
di file e cartelle, con path e subtask che possono contenere subtask
*/
class Task_client{
public:
  Task_client() = default;
  Task_client(std::shared_ptr<Task_composite>);

  void add_leaf(std::string);
  void add_composite(std::string);
  void go_up();
  void go_to_child(std::shared_ptr<Task_composite>);
  void bind_to_composite(std::shared_ptr<Task_composite>);
  void list_children();

  std::string get_curr_path();
  //ritorna la posizione nell'albero stampata stile unix

  ~Task_client() = default;
  //nessuna risorsa da deallocare manualmente
  
private:
  std::shared_ptr<Task_composite> curr_task;
  std::stack<shared_ptr<Task_composite>> curr_task_path;
};

#endif
