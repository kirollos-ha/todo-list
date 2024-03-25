#include "minitest.hpp"
#include "../src/include/task/all.hpp"

void test_task_components() { 
    test_suite("test consturction wih smart pointers"){
        Date d = Date::from(20, 10, 2024);
        test_case("parent and string constructors"){
            std::string root = "root", sub = "sub", lef = "leaf";
            std::string rootd = "root d", subd = "sub d", lefd = "leaf d";
            auto root_task = make_root_composite(root, rootd, d);
            auto composite = make_composite (sub, subd, d,root_task);
            ass_eq(root, root_task->get_name());
            ass_eq(rootd, root_task->get_description());
            ass_eq(sub, composite->get_name())
            ass_eq(subd, composite->get_description());
            ass_eq(composite, root_task->get_children().back());
            ass_eq(1, root_task->get_children().size());

            auto leaf = make_leaf(lef, lefd, d, root_task);
            ass_eq(leaf, root_task->get_children().back());
            ass_eq(lef, leaf->get_name());
            ass_eq(lefd, leaf->get_description());
            ass_eq(lef, leaf->get_name());
            ass_eq(2,root_task->get_children().size());
        }
    }

    test_suite("test drive") {
        Date d = Date::from(20, 10, 2024);
        std::string
            princeps_s = "tanto gentile e tanto onesta pare",
            strofa1_s = "strofa 1",
            strofa2_s = "strofa 2",
            s1v1_s = "tanto gentile e tanto onesta pare",
            s1v2_s = "la donna mia quand'ella altrui saluta,",
            s1v3_s = "ch'ogni lingua deven tremando muta",
            s1v4_s = "e li occhi no l'ardiscon di guardare",
            s2v1_s = "Ella si va, sentendosi laudare",
            s2v2_s = "benignamente d'umiltà vestuta",
            s2v3_s = "e par che sia una cosa venuta",
            s2v4_s = "da cielo in terra a miracol mostrare.";

        std::string
            princeps_d = "descrizione di : tanto gentile e tanto onesta pare",
            strofa1_d = "descrizione di : strofa 1",
            strofa2_d = "descrizione di : strofa 2",
            s1v1_d = "descrizione di : tanto gentile e tanto onesta pare",
            s1v2_d = "descrizione di : la donna mia quand'ella altrui saluta,",
            s1v3_d = "descrizione di : ch'ogni lingua deven tremando muta",
            s1v4_d = "descrizione di : e li occhi no l'ardiscon di guardare",
            s2v1_d = "descrizione di : Ella si va, sentendosi laudare",
            s2v2_d = "descrizione di : benignamente d'umiltà vestuta",
            s2v3_d = "descrizione di : e par che sia una cosa venuta",
            s2v4_d = "descrizione di : da cielo in terra a miracol mostrare.";
            
        auto princeps = make_root_composite(princeps_s, princeps_d, d);

        auto strofa1 = make_composite(strofa1_s, strofa1_d, d, princeps);
        auto s1v1 = make_leaf(s1v1_s, s1v1_d, d, princeps);
        auto s1v2 = make_leaf(s1v2_s, s1v2_d, d, princeps);
        auto s1v3 = make_leaf(s1v3_s, s1v3_d, d, princeps);
        auto s1v4 = make_leaf(s1v4_s, s1v4_d, d, princeps);

        strofa1->add(s1v1);
        strofa1->add(s1v2);
        strofa1->add(s1v3);
        strofa1->add(s1v4);
        princeps->add(strofa1);

        auto strofa2 = make_composite(strofa2_s, strofa2_d, d, princeps);
        auto s2v1 = make_leaf(s2v1_s, s2v1_d, d, strofa2);
        auto s2v2 = make_leaf(s2v2_s, s2v2_d, d, strofa2);
        auto s2v3 = make_leaf(s2v3_s, s2v3_d, d, strofa2);
        auto s2v4 = make_leaf(s2v4_s, s2v4_d, d, strofa2);

        test_case("controlla nomi strofa 1") {
            ass_eq(s1v1_s, s1v1->get_name());
            ass_eq(s1v2_s, s1v2->get_name());
            ass_eq(s1v3_s, s1v3->get_name());
            ass_eq(s1v4_s, s1v4->get_name());
        }

        test_case("controlla descrizioni strofa 1") {
            ass_eq(s1v1_d, s1v1->get_description());
            ass_eq(s1v2_d, s1v2->get_description());
            ass_eq(s1v3_d, s1v3->get_description());
            ass_eq(s1v4_d, s1v4->get_description());
        }

        test_case("controlla puntatori stroafa 1") {
            ass_eq(s1v1, strofa1->get_child(0));
            ass_eq(s1v2, strofa1->get_child(1));
            ass_eq(s1v3, strofa1->get_child(2));
            ass_eq(s1v4, strofa1->get_child(3));
        }

        test_case("controlla nomi strofa 2") {
            ass_eq(s2v1_s, s2v1->get_name());
            ass_eq(s2v2_s, s2v2->get_name());
            ass_eq(s2v3_s, s2v3->get_name());
            ass_eq(s2v4_s, s2v4->get_name());
        }

        test_case("controlla descrizioni strofa 2") {
            ass_eq(s2v1_d, s2v1->get_description());
            ass_eq(s2v2_d, s2v2->get_description());
            ass_eq(s2v3_d, s2v3->get_description());
            ass_eq(s2v4_d, s2v4->get_description());
        }

        test_case("controlla puntatori stroafa 2") {
            ass_eq(s2v1, strofa2->get_child(0));
            ass_eq(s2v2, strofa2->get_child(1));
            ass_eq(s2v3, strofa2->get_child(2));
            ass_eq(s2v4, strofa2->get_child(3));
        }
    }

    test_suite("cerca bambini") {
        Date d = Date::from(20, 10, 2030);

        std::string
            nome_radice = "radix", nome_primo = "filii", nome_altro = "caesar",
            desc_radice = "radesc", desc_primo = "filiidesc", desc_altro = "cauesardescr";
        auto radice = make_root_composite(nome_radice, desc_radice, d);
        auto primogenito = make_composite(nome_primo, desc_primo, d, radice);
        auto secondogenito = make_composite(nome_altro, desc_altro, d, radice);

        test_case("primogenito fullname") {
            auto x = radice->find_descendant(nome_primo);
            ass_t(x.has_value());
            ass_eq(*x, primogenito);
        }

        test_case("primogenito midname") {
            std::string target = "ili";
            auto x = radice->find_descendant(target);
            ass_t(x.has_value());
            ass_eq(*x, primogenito);
        }

        test_case("primogenito statname") {
            std::string target_start = "fil";
            auto x = radice->find_descendant(target_start);
            ass_t(x.has_value());
            ass_eq(*x, primogenito);
        }

        test_case("primogenito startname unit") {
            std::string unit_target_start = "f";
            auto x = radice->find_descendant(unit_target_start);
            ass_t(x.has_value());
            ass_eq(*x, primogenito);
        }

        test_case("primogenito endname") {
            std::string target_end = "ii";
            auto x = radice->find_descendant(target_end);
            ass_t(x.has_value());
            ass_eq(*x, primogenito);
        }

        test_case("primogenito endname unit") {
            std::string unit_target_end = "i";
            auto x = radice->find_descendant(unit_target_end);
            ass_t(x.has_value());
            ass_eq(*x, primogenito);
        }

        test_case("secondogenito") {
            auto x = radice->find_descendant(nome_altro);
            ass_t(x.has_value());
            ass_eq(*x, secondogenito);
        }

        test_case("secondogenito midname") {
            std::string target = "esa";
            auto x = radice->find_descendant(target);
            ass_t(x.has_value());
            ass_eq(*x, secondogenito);
        }

        test_case("secondogenito startname") {
            std::string target_start = "cae";
            auto x = radice->find_descendant(target_start);
            ass_t(x.has_value());
            ass_eq(*x, secondogenito);
        }

        test_case("secondogenito startname unit") {
            std::string unit_target_start = "c";
            auto x = radice->find_descendant(unit_target_start);
            ass_t(x.has_value());
            ass_eq(*x, secondogenito);
        }

        test_case("secondogenito endname") {
            std::string target_end = "sar";
            auto x = radice->find_descendant(target_end);
            ass_t(x.has_value());
            ass_eq(*x, secondogenito);
        }

        test_case("secondogenito endname unit") {
            std::string unit_target_end = "r";
            auto x = radice->find_descendant(unit_target_end);
            ass_t(x.has_value());
            ass_eq(*x, secondogenito);
        }


        test_case("figlio non trovato") {
            std::string target = "orefice maria ruggero";
            auto x = radice->find_descendant(target);
            ass_t(!x.has_value());
        }

        std::string nipote_nome="zzzzzzzzzzzzz", nipote_descrizione="d:zzzzzzzzzzz";
        auto nipote = make_leaf(nipote_nome, nipote_descrizione, d, secondogenito); 

        test_case("nipote") {
            std::string target = "zzz";
            auto x = radice->find_descendant(target);
            ass_t(x.has_value());
            ass_eq(*x, nipote);
        }

        test_case("senza figli") {
            std::string target = "";
            auto x = primogenito->find_descendant(target);
            ass_t(!x.has_value());
        }

        test_case("figli ma niente risultati") {
            std::string target = "pasquale";
            auto x = secondogenito->find_descendant(target);
            ass_t(!x.has_value());
        }

        test_case("nonno senza risultati") {
            std::string target = "pasquale";
            auto x = radice->find_descendant(target);
            ass_t(!x.has_value());
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
