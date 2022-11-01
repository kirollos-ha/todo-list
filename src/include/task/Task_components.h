#ifndef TODO_TASK_COMPONENTS_H
#define TODO_TASK_COMPONENTS_H

#include<string>
#include<list>
#include<memory>
#include<iostream>

class Task_component;
class Task_leaf;
class Task_composite;

class Task_component{
public:
  Task_component();
  explicit Task_component(std::string name);

  virtual std::string get_name();
  virtual void set_name(std::string new_name);

  virtual ~Task_component();

private:
  std::string name;
};

class Task_leaf : public Task_component{
public:
  Task_leaf();
  explicit Task_leaf(std::string name);

  virtual std::string get_name() override;
  virtual void set_name(std::string new_name) override;

  virtual ~Task_leaf();
};

class Task_composite : public Task_component{
public:
  Task_composite();
  Task_composite(std::string name);

  virtual std::string get_name() override;
  virtual void set_name(std::string new_name) override;

  void print_children();
  void detach_child(std::string target_name);
  void detach_child(std::shared_ptr<Task_component>);
  std::list<std::shared_ptr<Task_component>>* get_children();
  void add(std::shared_ptr<Task_component> new_child);

  virtual ~Task_composite();
private:
  std::list<std::shared_ptr<Task_component>>children;
};

//per inizializzare direttamente da smart pointer quando serve
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
