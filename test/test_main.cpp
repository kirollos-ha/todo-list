#include<iostream>
#include"test_task_components.hpp"

int main(){
	std::cout<<"testing...\n";
	test_task_components();
	if(!exp_failed){
		std::cout<<"ALL TESTS PASS!\n";
	}
	else{
		std::cout<<"some tests failed\n";
	}
	return 0;
}
