#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include<fstream>
#include<memory>
#include"../task/Task_components.h"

class File_parser{
public:
  File_parser();
  File_parser(std::ifstream ifs);
  std::shared_ptr<Task_composite> file_to_list(char const*);
  //usa composite_start, composite_end, add_leaf
  void composite_start();
  void composite_end();
  void add_leaf();

private:
  std::shared_ptr<Task_composite>root;
  std::shared_ptr<Task_composite>curr_parent;
  std::shared_ptr<Task_composite>curr_grandparent;
  //usati in: make_todo_list, compoisite_start, compoiste_end, add_leaf

  std::ifstream ifs;
  //usata in tutti i metodi
};

#endif
