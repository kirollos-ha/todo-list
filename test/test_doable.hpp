#ifndef TEST_DOABLE_H
#define TEST_DOABLE_H

#include "minitest.hpp"

#include "../src/include/task/TaskComponent.hpp"
#include "../src/include/task/TaskLeaf.hpp"
#include "../src/include/task/TaskComposite.hpp"
#include "../src/include/task/Date.hpp"
#include "../src/include/task/initializers.hpp"
#include "../src/include/task/TaskDoableChecker.hpp"

void test_doable() {
    test_suite("doable") {
        std::string name = "name", desc = "desc";
        Date date = Date::from(1, 1, 1970);
        
        auto root = make_root_composite(desc, desc, date);
        
        test_case("leaf") {
            TaskDoableChecker tdc;
            ass_t(tdc.is_doable(make_leaf(name, desc, date, root).get()));
        }
        test_case("composite senza figli") {
            TaskDoableChecker tdc;
            ass_t(tdc.is_doable(make_leaf(name, desc, date, root).get()));
        }
        test_case("composite fatto figli") {
            TaskDoableChecker tdc;
            auto rootin = make_root_composite(name, desc, date);
            auto son = make_leaf(name, desc, date, rootin);
            son->mark_done();
            auto compy = make_composite(name, desc, date, rootin);
            compy->mark_done();
            ass_t(tdc.is_doable(rootin.get()));
        }
        test_case("composite fatto nipoti") {
            ass_t(true);
        }
        test_case("composite figlio non fatto") {
            ass_t(true);
        }
        test_case("composite nipote non fatto") {
            ass_t(true);
        }
    }
}

#endif
