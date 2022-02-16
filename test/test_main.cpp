#include<iostream>
#include"test_task_components.h"
#include"test_fileio.h"
#include"test_ui.h"

int main(){
	std::cout<<"testing...\n";
	test_task_components();
	test_line_parsing();
	if(!exp_failed){
		std::cout<<"ALL TESTS PASS!\n";
	}
	else{
		std::cout<<"some tests failed\n";
	}
	return 0;
}
