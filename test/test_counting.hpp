#ifndef TEST_TASK_COUNTING_
#define TEST_TASK_COUNTING_H

#include "minitest.hpp"

#include "../src/include/task/TaskComponent.hpp"
#include "../src/include/task/TaskLeaf.hpp"
#include "../src/include/task/TaskComposite.hpp"

#include "../src/include/task/TaskCounter.hpp"

#include "initializers.hpp"

void test_counting() {
    test_suite("counting") {
        Date d = Date::from(1, 2, 3);
        std::string root_name = "root", root_desc = "root desc",
            child1_name = "child1", child1_desc = "child1 desc",
            child2_name = "child1", child2_desc = "child1 desc",
            child3_name = "child2", child3_desc = "child2 desc",
            child4_name = "child3", child4_desc = "child3 desc";
        auto root = make_root_composite(root_name, root_desc, d);
        auto firstborn = make_composite(child1_name, child1_desc, d, root);
        auto secondborn = make_leaf(child3_name, child3_desc, d, root);
        auto grandkid = make_composite(child2_name, child2_desc, d, firstborn);
        auto baby = make_composite(child4_name, child4_desc, d, grandkid);
        secondborn->mark_done();
        baby->mark_done();
        test_case("root") {
            TaskCounter tc;
            root->accept(&tc);
            ass_eq(tc.get_total(), 5);
            ass_eq(tc.get_done(), 2);
            ass_eq(tc.get_todo(), 3);
        }
        test_case("grand dad") {
            TaskCounter tc;
            firstborn->accept(&tc);
            ass_eq(tc.get_total(), 3);
            ass_eq(tc.get_done(), 1);
            ass_eq(tc.get_todo(), 2);
        }
        test_case("dad") {
            TaskCounter tc;
            grandkid->accept(&tc);
            ass_eq(tc.get_total(), 2);
            ass_eq(tc.get_done(), 1);
            ass_eq(tc.get_todo(), 1);
        }
        test_case("leaf") {
            TaskCounter tc;
            baby->accept(&tc);

            ass_eq(tc.get_total(), 1);
            ass_eq(tc.get_done(), 1);
            ass_eq(tc.get_todo(), 0);
        }
    }
}

#endif
