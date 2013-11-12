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
  string url = "http://dev.mistakenlypriced.com";
  
  while ((c = getopt (argc, argv, "v::u::")) != -1)
  {
	switch (c)
	{
		case 'v' :
		args.push_back("verbose");
		g_verbose = 1;
		break;
		case 'u':
		args.push_back("url");
		char tmp[200];
		sprintf(tmp, "%s", optarg);
		cout<<tmp;
		url = tmp;
		break;
	}
  }

  logger.log_info("Initializing");
  
  curl_helper curl = curl_helper();

  string str = curl.simple_get(url) ;
  cout<<str<<endl;
}
