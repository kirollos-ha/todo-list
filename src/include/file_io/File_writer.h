#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include<fstream>
#include"../task/Task_components.h"

class File_writer{
public:
  File_writer();
  File_writer(std::ofstream& ofs);

  void write_file(char const*, std::shared_ptr<Task_composite>);
  //entrambe usano list_to_file
private:
  std::ofstream ofs;

  void list_to_file(std::shared_ptr<Task_composite>);
  //usa put_composite e put_leaf
  void put_composite(std::shared_ptr<Task_composite>);
  void put_leaf(std::shared_ptr<Task_leaf>);
};

#endif
