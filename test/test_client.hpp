#ifndef TEST_CLIENT_H
#define TEST_CLIENT_H

#include "minitest.hpp"
#include "../src/include/ui/TaskClient.hpp"
#include "../src/include/task/initializers.hpp"

void test_client() {
    test_suite("adding") {
        Date date = Date::from(1, 1, 1970);
        test_case("non cambia altri elementi") {
            std::string root = "root";
            std::string kid1 = "kid1", kid1d = "kid1d";
            std::string kid2 = "kid2", kid2d = "kid2d";
            std::string kid3 = "kid3", kid3d = "kid3d";

            TaskClient tc(make_root_composite(root, root, date));
            ass_eq(0, tc.curr_n_children());

            tc.add_leaf(kid1, kid1d, date);
            ass_eq(1, tc.curr_n_children());
            ass_eq("kid1",
                   tc.get_child(0)->get_name());
            ass_eq("kid1d",
                   tc.get_child(0)->get_description());

            tc.add_leaf(kid2, kid2d, date);
            ass_eq(2, tc.curr_n_children());
            ass_eq("kid1",
                   tc.get_child(0)->get_name());
            ass_eq("kid1d",
                   tc.get_child(0)->get_description());
            ass_eq("kid2",
                   tc.get_child(1)->get_name());
            ass_eq("kid2d",
                   tc.get_child(1)->get_description());

            tc.add_leaf(kid3, kid3d, date);
            ass_eq(3, tc.curr_n_children());
            ass_eq("kid1",
                   tc.get_child(0)->get_name());
            ass_eq("kid1d",
                   tc.get_child(0)->get_description());
            ass_eq("kid2",
                   tc.get_child(1)->get_name());
            ass_eq("kid2d",
                   tc.get_child(1)->get_description());
            ass_eq("kid3",
                   tc.get_child(2)->get_name());
            ass_eq("kid3d",
                   tc.get_child(2)->get_description());
        }

        test_case("add twice") {
            
        }
    }
    test_suite("removing") {
        test_case("fantoccio") {
            ass_t(true);
        }
    }
    test_suite("editing") {
        test_case("fantoccio") {
            ass_t(true);
        }
    }
}

#endif
