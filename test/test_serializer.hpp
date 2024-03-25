#ifndef TEST_SERIALIZER_H
#define TEST_SERIALIZER_H

#include<iostream>
#include<fstream>

#include "minitest.hpp"

#include "../src/include/ui/TaskClient.hpp"
#include "../src/include/serializers/TaskSerializer.hpp"
#include "../src/include/serializers/TaskFileParser.hpp"

void test_serializer() {
    test_suite("serializer") {
        test_case("symmetrical") {
            std::ifstream ifs("test/files/serialized");
            std::ofstream ofs("test/files/out");
            TaskClient tc(ifs);
            tc.write(ofs);

            ifs.close();
            ofs.close();

            std::ifstream ii1("files/serialized"), ii2("files/out");
            std::string s1, s2;

            while(std::getline(ii1, s1) && std::getline(ii2, s2)) {
                ass_eq(s1, s2);
            }
            ass_f(std::getline(ii1, s1));
            ass_f(std::getline(ii2, s2));
        }
    }
}

#endif
