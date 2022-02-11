#ifndef MINITEST_HEADER
#define MINITEST_HEADER

#include<iostream>
#include<string>

std::string suite_name;
std::string test_name;
bool exp_failed = 0;

//test cases
#define test_case(name)test_name = #name;\
				   if(true)

//suites
#define test_suite(name)suite_name = #name;\
		    if(true)

//trailing if(true) to accept curly braces after beginning of suite/case
//makes syntax more standard and legible

//here if(true)wrapping the macros' content to avoid name clashing
//expect
#define exp_eq(exp, act)if(true){\
				auto exp_val = (exp);\
				auto act_val = (act);\
			  if(exp_val != act_val){\
					std::cout<<#act<<" is not equal to "<<#exp<<'\n';\
					std::cout<<#exp<<" is "<<exp_val<<'\n';\
					std::cout<<#act<<" is "<<act_val<<'\n';\
					std::cout<<"in test : "<<test_name<<'\n';\
					std::cout<<"in suite : "<<suite_name<<std::endl;\
					exp_failed = 1;\
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
				std::cout<<"in test : "<<test_name<<'\n';\
				std::cout<<"in suite : "<<suite_name<<std::endl;\
				std::cout<<"assertion failed, now aborting...\n";\
				exit(1);\
			}\
			};


#define exp_t(condition) if(!(condition)){\
					  std::cout<<#condition<<" was supposed to be true but is false\n";\
					  std::cout<<"in test : "<<test_name<<'\n';\
					  std::cout<<"in suite : "<<suite_name<<std::endl;\
						exp_failed = 1;\
					 }

#define ass_t(condition) if(!(condition)){\
					  std::cout<<#condition<<" was supposed to be true but is false\n";\
					  std::cout<<"in test : "<<test_name<<'\n';\
					  std::cout<<"in suite : "<<suite_name<<std::endl;\
						std::cout<<"assertion failed, now aborting...";\
					  exit(1);\
					 }

#endif //MINITEST_HEADER
