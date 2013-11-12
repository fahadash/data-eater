#include "../curl-helper/curl_session.h"
#include "../shared/vars.h"
#include "../shared/args.h"
#include "../log/log.h"
#include "../model/form_data.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <unistd.h>

int main(int argc, char **argv)
{
  
  
  g_verbose = 0;
  log logger;
  cout<<"Data Eater Test"<<endl;
  string url = "http://dev.mistakenlypriced.com";

  logger.log_info("Initializing");
  
  curl_session curl = curl_session();

  form_data data;

  data.add("firstname","Muhammad");
  data.add("lastname", "fahad");

  

  string str = curl.get(url);
  str = curl.post(url, data);
  cout<<str<<endl;
}
