#include "print_funcs.h" 
#include "version.h"
#include <sstream>

std::string GetHelloWorld(){
	return "Hello, World!";
}

int GetMajorVerion() {
	return PROJECT_VERSION_MAJOR;
}

int GetMinorVerion() {
	return PROJECT_VERSION_MINOR;
}

int GetPatchVerion() {
	return PROJECT_VERSION_PATCH;
}

std::string GetVersion() {
	std::stringstream str;
	str << GetPatchVerion();
	return str.str();
}