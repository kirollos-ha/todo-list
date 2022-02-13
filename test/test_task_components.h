#include "minitest.hpp"
#include "../src/include/task/Task_components.h"

void test_task_components(){
  test_suite(test consturction wih smart pointers){
    test_case(no param consturctors){
      auto composite = make_composite();
      ass_eq("",composite->get_name());
      auto leaf = make_leaf();
      ass_eq("",leaf->get_name());
    }

    test_case(string constructors){
      auto composite = make_composite("composite name number 1");
      ass_eq("composite name number 1",composite->get_name());
      auto leaf = make_leaf("leaf name number 1");
      ass_eq("leaf name number 1",leaf->get_name());
    }

    test_case(parent and string constructors){
      auto root_task = make_composite("root task");
      auto composite = make_composite ("composite 2",root_task);
      ass_eq("composite 2",composite->get_name());
      ass_eq("composite 2",root_task->get_children()->back()->get_name());
      ass_eq(1,root_task->get_children()->size())

      auto leaf = make_leaf("leaf 2",root_task);
      ass_eq("leaf 2",leaf->get_name());
      ass_eq("leaf 2",root_task->get_children()->back()->get_name());
      ass_eq(2,root_task->get_children()->size());
    }
  }

  test_suite(test drive){
    auto princeps = make_composite("tanto gentile e tanto onesta pare");

    auto strofa1 = make_composite("strofa1");
    auto s1v1 = make_leaf("tanto gentile e tanto onesta pare");
    auto s1v2 = make_leaf("la donna mia quand'ella altrui saluta,");
    auto s1v3 = make_leaf("ch'ogni lingua deven tremando muta");
    auto s1v4 = make_leaf("e li occhi no l'ardiscon di guardare");

    strofa1->add(s1v1);
    strofa1->add(s1v2);
    strofa1->add(s1v3);
    strofa1->add(s1v4);
    princeps->add(strofa1);

    auto strofa2 = make_composite("strofa2",princeps);
    auto s2v1 = make_leaf("Ella si va, sentendosi laudare",strofa2);
    auto s2v2 = make_leaf("benignamente d'umiltà vestuta",strofa2);
    auto s2v3 = make_leaf("e par che sia una cosa venuta",strofa2);
    auto s2v4 = make_leaf("da cielo in terra a miracol mostrare.",strofa2);

    test_case(controlla i nomi strofa 1){
      ass_eq("tanto gentile e tanto onesta pare",s1v1->get_name());
      ass_eq("la donna mia quand'ella altrui saluta,",s1v2->get_name());
      ass_eq("ch'ogni lingua deven tremando muta",s1v3->get_name());
      ass_eq("e li occhi no l'ardiscon di guardare",s1v4->get_name());
    }
  }
}

//TODO codesti che son facendi
  /*
  test_suite(task_composite tests){
    test_case(adding leaves){

    }
    test_case(adding composites){

    }
    test_case(grandparents){

    }
  }
  */
// testa rimozione da composite
  /*
    test_case(controlla i nomi strofa 2){

    }
  */
