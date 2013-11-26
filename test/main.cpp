#include <tut/tut.hpp>
#include <tut_reporter.h>
#include <iostream>
#include <cstring>
#include <string>
using std::exception;
using std::cerr;
using std::endl;
using std::cout;
using std::string;

string g_test_datapath;


namespace tut
{
	test_runner_singleton runner;
}


int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][strlen(argv[1]) - 1] == '/')
	{ 
		cout<<"Usage: run_tests data_dir"
			<<endl
			<<"Example: run_tests ~/data-eater/test/data"
			<<endl
			<<endl;

		return -1;
	}
	g_test_datapath = argv[1];

	tut::reporter reporter;
	tut::runner.get().set_callback(&reporter);
	tut::runner.get().run_tests();

	return !reporter.all_ok();
}
