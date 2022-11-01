#ifndef CLI_TASK_CLIENT_INTERFACE_H
#define CLI_TASK_CLIENT_INTERFACE_H

#include<iostream>
#include<memory>

#include"Task_client.h"
#include"Command_line_parser.h"

/* commandi e significati
"addl", ADD_LEAF
"addc", ADD_COMPOSITE
"ls", LIST_CHILDREN
"ct", CHANGE_TASK
"rm", REMOVE
"mv", RENAME
"pwt", PRINT_WORKING_TASK
*/

class CLI_client_interface{
public:
  Cli_parser() = delete;//non si inizializza un'interfaccia al niente
  Cli_parser(std::shared_ptr<Task_client>task_client):task_client(task_client){}

  std::string get_CLI_input(){
    std::cout<<"What do you want to do now?\nInsert command :";
    std::string input;
    std::getline(std::cin,input);
  }

  Cli_command parse_string(std::string input){
    parser.parse_string(input);
    command = parser.return_command();
  }

  void execute_parsed(){
    //scusi lo switch gigante
    switch(command.action){
      case "addl":
      task_client.add_leaf(command.first_param);
      break;

      case "addc":
      task_client.add_composite(command.first_param);
      break;

      case "ls":
      task_client.list_children();
      break;

      case "ct":
      //se . se .. else
      break;

      case "rm":
      //se . se ..(eviterei) else
      break;

      case "mv":
      //se . se ..(eviterei) else
      break;

      case "pwt":
      std::cout<<task_client.get_curr_path()<<std::endl;
      break;
    }
  }
private:
  Cli_command command;
  Command_line_parser parser;
  std::shared_ptr<Task_client>task_client;
};

#endif
