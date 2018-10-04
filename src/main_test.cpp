#define BOOST_TEST_MODULE test_main
#include "print_funcs.h"
#include "version.h"
#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(test_suite_main)
BOOST_AUTO_TEST_CASE(test_version_valid)
{
	BOOST_CHECK(GetMajorVerion() == PROJECT_VERSION_MAJOR);
	BOOST_CHECK(GetMinorVerion() == PROJECT_VERSION_MINOR);
	BOOST_CHECK(GetPatchVerion() == PROJECT_VERSION_PATCH);
}
BOOST_AUTO_TEST_SUITE_END()


