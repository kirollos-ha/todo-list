#include<iostream>
#include"test_task_components.hpp"
#include"test_date.hpp"
#include"test_client.hpp"
#include "test_counting.hpp"
#include "test_serializer.hpp"

int main(){
	std::cout<<"testing...\n";
	test_task_components();
    test_date();
    test_client();
    test_counting();
    test_serializer();
	if(!exp_failed){
		std::cout<<"ALL TESTS PASS!\n";
	}
	else{
		std::cout<<"some tests failed\n";
	}
	return 0;
}
