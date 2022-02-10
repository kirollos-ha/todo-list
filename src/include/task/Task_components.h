#ifndef TODO_TASK_COMPONENTS_H
#define TODO_TASK_COMPONENTS_H

#include<string>
#include<list>
#include<memory>
#include<iostream>//speriamo che non diventi un inferno di std::cout<<"aituo"

class Task_component;
class Task_leaf;
class Task_composite;
//per poter passare un Task_composite come parent a tutte le classi

class Task_component{
public:
  Task_component();
  Task_component(std::string name);
  Task_component(Task_composite& parent);
  Task_component(std::string name, Task_composite& parent);

  virtual void remove();

  virtual std::string get_name();
  virtual void set_name(std::string new_name);

  virtual std::shared_ptr<Task_composite>get_parent();

  virtual ~Task_component() = default;
private:
  //entrambi gli attributi gestiti unicamente dall'interfaccia data da Task_component
  std::string name;
  std::shared_ptr<Task_composite>parent;
  //possibile che uno stesso task come figlio di coso (con un pointer nella lista parent.children che lo indica)
  //e padre di al di altro (quindi con un pointer parent di un task che lo indica)
  //impossibile quindi usare std::unique_ptr per entrambi i puntatori
};

class Task_leaf : public Task_component{
public:
  Task_leaf();
  Task_leaf(std::string name);
  Task_leaf(Task_composite& parent);
  Task_leaf(std::string name, Task_composite& parent);

  virtual void remove() override;

  virtual std::string get_name() override;
  virtual void set_name(std::string new_name) override;

  virtual std::shared_ptr<Task_composite>get_parent() override;

  virtual ~Task_leaf() = default;
};

class Task_composite : public Task_component{
public:
  Task_composite();
  Task_composite(std::string name);
  Task_composite(Task_composite& parent);
  Task_composite(std::string name, Task_composite& parent);

  virtual void remove() override;

  virtual std::string get_name() override;
  virtual void set_name(std::string new_name) override;

  virtual std::shared_ptr<Task_composite>get_parent() override;

  void add(std::shared_ptr<Task_component> new_child);
  void print_children();
  void release_child(std::string target_name);
  std::shared_ptr<std::list<std::shared_ptr<Task_component>>>get_children();
  //TODO implementare i seguenti
  //void add_leaf(std::string name);//crea leaf e la aggiunge
  //void add_composite(std::string name);//crea composite e lo aggiunge
  //void release_child(int target_index);

  virtual ~Task_composite() = default;
private:
  std::list<std::shared_ptr<Task_component>>children;
};

//agli smart pointer non piace gestire oggetti allocati staticamente, quindi
//creiamo tutto con smart pointer

std::shared_ptr<Task_leaf>make_leaf();
std::shared_ptr<Task_leaf>make_leaf(std::string name);
std::shared_ptr<Task_leaf>make_leaf(std::shared_ptr<Task_composite>parent);
std::shared_ptr<Task_leaf>make_leaf(std::string name,
  std::shared_ptr<Task_composite>parent);

std::shared_ptr<Task_composite>make_composite();
std::shared_ptr<Task_composite>make_composite(std::string name);
std::shared_ptr<Task_composite>make_composite(std::shared_ptr<Task_composite>parent);
std::shared_ptr<Task_composite>make_composite(std::string name,
  std::shared_ptr<Task_composite>parent);

#endif
