#include "../curl-helper/curl_helper.h"
#include "../shared/vars.h"
#include "../shared/args.h"
#include "../log/log.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <unistd.h>

int main(int argc, char **argv)
{
  
  int c;
  g_verbose = 0;
  log logger;
  cout<<"Data Eater Test"<<endl;

  while ((c = getopt (argc, argv, "v::")) != -1)
  {
	switch (c)
	{
		case 'v' :
		args.push_back("verbose");
		g_verbose = 1;
	}
  }

  logger.log_info("Initializing");
  
  curl_helper curl = curl_helper();

  string str = curl.simple_get("http://dev.msitakenlypriced.com") ;
  printf(str.c_str());
}
