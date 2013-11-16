#include "../xml-helper/xml_helper.h"
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
  cout<<"XML Test"<<endl;
  string xml = "<?xml version=\"1.0\" ?>\r\n <test></test>";


  logger.log_info("Initializing");
  //xml_document doc;
  //doc.load_xml(xml);

  cout<<"loaded"<<endl;
}
