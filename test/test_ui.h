#include "minitest.hpp"
#include "../src/include/ui/Command_line_parser.h"

void test_line_parsing(){
  test_suite(no semicolons){

    test_case(leaf){
      Command_line_parser parser;
      parser.parse_string("addl compra tanti tanti fusilli");
      CLI_command command = parser.return_command();
      ass_eq("addl",command.action);
      ass_eq("compra tanti tanti fusilli",command.first_param);
      ass_eq("",command.second_param);
    }

    test_case(composite){
      Command_line_parser parser;
      parser.parse_string("addc prendi la roba per cena");
      CLI_command command = parser.return_command();
      ass_eq("addc",command.action);
      ass_eq("prendi la roba per cena", command.first_param);
      ass_eq("", command.second_param);
    }

    test_case(somethnig else entirely){
      Command_line_parser parser;
      parser.parse_string("         spazii        tanti  spazii nel  nome  ");
      CLI_command command = parser.return_command();
      ass_eq("spazii",command.action);
      ass_eq("tanti  spazii nel  nome",command.first_param);
      ass_eq("",command.second_param);
    }
  }
  test_suite(semicolons){
    test_case(a leaf... a composite){
      Command_line_parser parser;
      parser.parse_string("mv   compra un sacco di pasta   ;  compra poca   pasta  ");
      CLI_command command = parser.return_command();
      ass_eq("mv", command.action);
      ass_eq("compra un sacco di pasta",command.first_param);
      ass_eq("compra poca   pasta",command.second_param);
    }
    test_case(or something else entirely?){
      Command_line_parser parser;
      parser.parse_string("  ceci-est-une-functione holalalala;louisarmstrong");
      CLI_command command = parser.return_command();
      ass_eq("ceci-est-une-functione", command.action);
      ass_eq("holalalala", command.first_param);
      ass_eq("louisarmstrong", command.second_param);
    }
  }
  //I hate catchy choruses and I'm a hypocrite, hungry hungry hypocrite
}
