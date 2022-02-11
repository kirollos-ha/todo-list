#ifndef TODO_TASK_COMPONENTS_H
#define TODO_TASK_COMPONENTS_H

#include<string>
#include<list>
#include<memory>
#include<iostream>

class Task_component;
class Task_leaf;
class Task_composite;
//per poter passare un Task_composite come parent a tutte le classi

class Task_component{
public:
  Task_component();
  explicit Task_component(std::string name);
  explicit Task_component(std::shared_ptr<Task_composite> parent);
  Task_component(std::string name, std::shared_ptr<Task_composite> parent);

  virtual std::string get_name();
  virtual void set_name(std::string new_name);

  virtual std::shared_ptr<Task_composite>get_parent();
  virtual void detach_parent();
  //TODO, vedi se potrebbe mai servirti set_parent();
  virtual std::shared_ptr<Task_component>get_self_ptr();

  virtual ~Task_component();
private:
  std::string name;
  std::shared_ptr<Task_component>self_ptr;
  //shared_ptr da cui copieremo gli shared_ptr che punteranno a questo component
  std::shared_ptr<Task_composite>parent;
};

class Task_leaf : public Task_component{
public:
  Task_leaf();
  explicit Task_leaf(std::string name);
  explicit Task_leaf(std::shared_ptr<Task_composite> parent);
  Task_leaf(std::string name, std::shared_ptr<Task_composite> parent);

  virtual std::string get_name() override;
  virtual void set_name(std::string new_name) override;

  virtual std::shared_ptr<Task_composite>get_parent() override;
  virtual std::shared_ptr<Task_component>get_self_ptr() override;

  virtual ~Task_leaf();
  //non maneggia risorse che non siamo di Task_component, quindi niente
};

class Task_composite : public Task_component{
public:
  Task_composite();
  Task_composite(std::string name);
  Task_composite(std::shared_ptr<Task_composite> parent);
  Task_composite(std::string name, std::shared_ptr<Task_composite> parent);

  virtual std::string get_name() override;
  virtual void set_name(std::string new_name) override;

  virtual std::shared_ptr<Task_composite>get_parent() override;
  virtual std::shared_ptr<Task_component>get_self_ptr() override;

  void add(std::shared_ptr<Task_component> new_child);
  void print_children();
  void detach_child(std::string target_name);
  void detach_child(std::shared_ptr<Task_component>);
  std::shared_ptr<std::list<std::shared_ptr<Task_component>>>get_children();
  //TODO implementare i seguenti
  //void add_leaf(std::string name);//crea leaf e la aggiunge
  //void add_composite(std::string name);//crea composite e lo aggiunge
  //void release_child(int target_index);

  virtual ~Task_composite();
private:
  std::list<std::shared_ptr<Task_component>>children;
};

//per inizializzare direttamente tramite smart pointer
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
