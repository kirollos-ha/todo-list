#include"File_parser.h"

std::shared_ptr<Task_composite> File_parser::file_to_list(char const* filepath){
  ifs.open(filepath);
  auto root = make_composite("Root of list");
  std::string param;
  ifs>>param;
  //TODO ricorda che devi fare il loop che legge tutte le righe di sta cosa
  //a ogni riga cs? ce, or something else entirely?:
  //la cosa sarebbe riducibile a s,e,l invece di cs,ce,l, vedi poi se ne vale la pena
  if(param == "cs"){
    composite_start();
  }
  else if(param == "ce"){
    composite_end();
  }
  else if(param == "l"){
    add_leaf();
  }
  return root;
}

void File_parser::composite_start(){
  std::string input;
  ifs>>input;
  curr_parent = make_composite(input);
  curr_parent->get_parent()->add(curr_parent);
}

void File_parser::composite_end(){
  curr_parent = curr_parent->get_parent();
}

void File_parser::add_leaf(){
  std::string input;
  ifs>>input;
  curr_parent->add(make_leaf(input));
}
