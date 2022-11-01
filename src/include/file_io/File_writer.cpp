#include"File_writer.h"

void File_writer::write_file(char const* filepath,
  std::shared_ptr<Task_composite>source){
  ofs.open(filepath);
  list_to_file(source);
}

void File_writer::list_to_file(std::shared_ptr<Task_composite>source){
  //source nodo root della lista, non lo scriviamo a file
  //TODO ricorda di rivedere meglio la correttezza di ste chiamate ricorsive e se fa tutto
  for(auto child:*(source->get_children())){
    if(auto tc = dynamic_cast<Task_composite*>(child.get())){//dynamic cast non fa con shared
      //se child folia est non
      put_composite(std::shared_ptr<Task_composite>(tc));
    }
    else{
      put_leaf(std::shared_ptr<Task_leaf>(static_cast<Task_leaf*>(child.get())));
    }
  }
}

void File_writer::put_composite(std::shared_ptr<Task_composite>c){
  ofs<<"cs "<<c->get_name()<<'\n';
  //magari sarebbe una buona idea mettere questo loop in un metodo put_children();
  for(auto child:*(c->get_children())){
    if(auto tc = dynamic_cast<Task_composite*>(child.get())){
      put_composite(std::shared_ptr<Task_composite>(tc));
    }
    else{
      put_leaf(std::shared_ptr<Task_leaf>(static_cast<Task_leaf*>(child.get())));
    }
  }
  ofs<<"ce\n";
}

void File_writer::put_leaf(std::shared_ptr<Task_leaf>l){
 ofs<<"l "<<l->get_name()<<'\n';
}
