#include "print_funcs.h"
#include <iostream>
int main(char argc, char** argv){
	std::cout << "build " << GetVersion() << std::endl;
	std::cout<<GetHelloWorld();
}

