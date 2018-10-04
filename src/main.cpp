#include "print_funcs.h"
#include <iostream>
int main(int argc, char** argv){
	std::cout << "build " << GetVersion() << std::endl;
	std::cout<<GetHelloWorld();
	return 0;
}

