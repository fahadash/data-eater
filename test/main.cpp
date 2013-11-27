#include <tut/tut.hpp>
#include <tut_reporter.h>
#include <unistd.h>
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
	
	//Process command-line args
	int c;
	string group_name = "";

	while ((c = getopt (argc, argv, "g:")) != -1)
	{
		string arg;
		if (optarg != 0)
		{
			arg = optarg;
		}
		else
		{
			arg = "";
		}
		
		if (c == 'g')
		{
			if (arg.length() == 0)
			{
				cout<<"Error: option -g requires a group name.";
				return -1;
			}
			else
			{
				group_name = arg;
			}
		}
		else if (c == '?')
		{
			return -1;
		}
		
	}
	

	if (optind < argc)
	{
		g_test_datapath = argv[optind];
	}
	else
	{		
		cout<<"Usage: run_tests [-g group-name] data_dir"
			<<endl
			<<"Example: run_tests ~/data-eater/test/data"
			<<endl
			<<"Example: run_tests -g xml ~/data-eater/test/data"
			<<endl
			<<endl;
		return -1;
	}


	if (g_test_datapath.substr(0, g_test_datapath.length()) == "/")
	{
		g_test_datapath = g_test_datapath.substr(0, g_test_datapath.length() - 1);
	}

	cout<<"Data path="<<g_test_datapath<<endl;

	
	tut::reporter reporter;
	tut::runner.get().set_callback(&reporter);

	if (group_name.length() != 0)
	{
		cout<<"Running single group test[group name="<<group_name<<"]..."<<endl;
		tut::runner.get().run_tests(group_name);
	}
	else
	{
		cout<<"Running all tests.."<<endl;
		tut::runner.get().run_tests();
	}


	return !reporter.all_ok();
}
