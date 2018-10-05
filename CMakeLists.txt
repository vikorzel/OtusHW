cmake_minimum_required(VERSION 3.2)
enable_testing()

if ($ENV{TRAVIS_BUILD_NUMBER})
	message("Build number: $ENV{TRAVIS_BUILD_NUMBER}")
	project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	message("ENV.TRAVIS_BUILD_NUMBER not found")
	project(helloworld VERSION 0.0.1)
endif()

if(${CMAKE_MINOR_VERSION} GREATER 10)
	cmake_policy(SET CMP0074 NEW)
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
link_directories(${Boost_LIBRARY_DIR})
configure_file(tmpl/version.h.in ${PROJECT_SOURCE_DIR}/src/version.h)
add_library(printer src/print_funcs.cpp)
add_executable(helloworld_cli 	src/main.cpp 
				src/print_funcs.cpp
				src/print_funcs.h
				src/version.h)							

add_executable(helloworld_tst src/main_test.cpp)

if(MSVC)
	set_target_properties(helloworld_cli helloworld_tst PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED NO
		OUTPUT_NAME "helloworld"
	)
else()
	set_target_properties(helloworld_cli helloworld_tst PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED NO
		COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
		OUTPUT_NAME "helloworld"
	)
endif()

set_target_properties(helloworld_tst PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
	)
target_link_libraries(	helloworld_cli
						printer
					  )

target_link_libraries(	helloworld_tst
						${Boost_LIBRARIES}
						printer		
					 )

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT hard.slot@gmail.com)
include (CPack)


add_test(test_version_valid helloworld_tst)
