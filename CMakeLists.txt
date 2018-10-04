cmake_minimum_required(VERSION 3.2)
enable_testing()
if (DEFINED $ENV{TRAVIS_BUILD_NUMBER})
	project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project(helloworld VERSION 0.0.1)
endif()
cmake_policy(SET CMP0074 NEW)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
link_directories(${Boost_LIBRARY_DIR})
configure_file(tmpl/version.h.in ../src/version.h)
add_library(printer src/print_funcs.cpp)
add_executable(helloworld_cli 	src/main.cpp 
				src/print_funcs.cpp
				src/print_funcs.h
				src/version.h)							

add_executable(helloworld_tst src/main_test.cpp)



set_target_properties(helloworld_cli helloworld_tst PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED NO)

set_target_properties(helloworld_tst PROPERTIES
	COMPILE_DEFENITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
	)
target_link_libraries(helloworld_cli
			printer)

target_link_libraries(helloworld_tst
	printer
	#${Boost_LIBRARIES}
)


install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPAK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT hard.slot@gmail.com)
include (CPack)


add_test(test_version_valid helloworld_tst)
