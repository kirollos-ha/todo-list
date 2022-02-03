#ifndef MINITEST_HEADER
#define MINITEST_HEADER

#include<iostream>

std::string suite_name;
std::string test_name;
bool test_failed = 0;//did a test fail in the current suite?
bool assert_failed = 0;//did an assert fail?

//test cases
#define test_case(name)test_name = #name;\
				   if(true)

//suites
#define test_suite(name) suite_name = #name;\
		    test_failed = 0;\
		    if(true)

//the if(true) in the suites and tests is there so that adding curly braces doesn't break everything
//in the assertions it is used to avoid name clashing since having 20 different "exp_val"s floating around at all times will make the compiler quit its job
//declaring them in a conditional will make the current "exp_val" not interfere with other assertions' "exp_val"

//expect
#define exp_eq(exp, act)if(true){\
			auto exp_val = (exp);\
			auto act_val = (act);\
		        if(exp_val != act_val){\
				std::cout<<#act<<" is not equal to "<<#exp<<'\n';\
				std::cout<<#exp<<" is "<<exp_val<<'\n';\
				std::cout<<#act<<" is "<<act_val<<'\n';\
		        	test_failed = 1;\
				std::cout<<"in test "<<test_name<<'\n';\
				std::cout<<"in suite "<<suite_name<<std::endl;\
			}\
			};

//assert
#define ass_eq(exp, act)if(true){\
			auto exp_val = (exp);\
			auto act_val = (act);\
		        if(exp_val != act_val){\
				std::cout<<#act<<" is not equal to "<<#exp<<'\n';\
				std::cout<<#exp<<" is "<<exp_val<<'\n';\
				std::cout<<#act<<" is "<<act_val<<'\n';\
		        	test_failed = 1;\
				assert_failed = 1;\
				std::cout<<"in test "<<test_name<<'\n';\
				std::cout<<"in suite "<<suite_name<<std::endl;\
				exit(1);\
			}\
			};


#define exp_t(condition) if(!(condition)){\
					  std::cout<<#condition<<" was supposed to be true but is false\n";\
					  test_failed=1;\
					  std::cout<<"in test "<<test_name<<'\n';\
					  std::cout<<"in suite "<<suite_name<<std::endl;\
					 }

#define ass_t(condition) if(!(condition)){\
					  std::cout<<#condition<<" was supposed to be true but is false\n";\
					  test_failed=1;\
					  assert_failed=1;\
					  std::cout<<"in test "<<test_name<<'\n';\
					  std::cout<<"in suite "<<suite_name<<std::endl;\
					  exit(1);\
					 }

#endif //MINITEST_HEADER
