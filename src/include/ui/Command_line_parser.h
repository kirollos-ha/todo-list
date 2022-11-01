#ifndef COMMAND_LINE_PARSER_TASK_H
#define COMMAND_LINE_PARSER_TASK_H

#include<string>
#include<unordered_map>

/* commandi e significati
"addl", ADD_LEAF
"addc", ADD_COMPOSITE
"ls", LIST_CHILDREN
"ct", CHANGE_TASK
"rm", REMOVE
"mv", RENAME
"pwt", PRINT_WORKING_TASK
*/

struct CLI_command{
  std::string action;
  std::string first_param;
  std::string second_param; //usato per rename e nient'altro
};

class Command_line_parser{
public:
  void parse_string(std::string s){
    input = s;
    command.action = get_action(); //prima parola, poi spazio
    command.first_param = get_first_param(); //tra la prima parola e fine/';'
    if(semicolon_index){
      command.second_param = get_second_param(); //tutto il resto
    }
  }
  CLI_command return_command(){
    return command;
  }
private:
  CLI_command command;
  std::string input;
  int index_after_action;
  int semicolon_index = 0;

  int advance_until_space(int start){
    while(start!=input.size() && input[start]!=' ') ++start;
    return start;
  }
  int advance_while_space(int start){
    while(start!=input.size() && input[start]==' ') ++start;
    return start;
  }
  std::string get_action(){
    int first = advance_while_space(0);
    int last = advance_until_space(first);
    index_after_action = last;
    return input.substr(first,last-first);//last non incluso
  }

  std::string get_first_param(){
    int first = advance_while_space(index_after_action);
    int end = first + 1;
    while(end!=input.size() && input[end]!=';') ++end;

    if(end!=input.size()){//e siamo quindi usciti per punto e virgola
      semicolon_index = end;
    }
    int last = end-1;//comunque sia uscito, input[end] non lo voglio
    while(input[last]==' ') --last;

    return input.substr(first,last-first+1);//last incluso
  }

  std::string get_second_param(){
    int first = advance_while_space(semicolon_index + 1);
    int last = input.size()-1;
    while(input[last] == ' ') --last;

    return(input.substr(first,last-first+1));//last incluso
  }
};

#endif
