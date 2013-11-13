#include "../tidy-helper/tidy_converter.h"
#include "../shared/vars.h"
#include "../log/log.h"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


int main(int argc, char **argv)
{


  g_verbose = 0;
  log logger;
  cout<<"Tidy Converter Test"<<endl;
  string html = "<title>Foo</title><p>Foo!";


  logger.log_info("Initializing");
  tidy_converter converter;
  string result = converter.convert_xhtml(html);
  cout<<result<<endl;
}
