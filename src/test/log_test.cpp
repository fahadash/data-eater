#include "../log/log.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  cout<<"Logging module test..."<<endl;
  dataeater::log logger;

  logger.log_info("This is information message");
  logger.log_warning("This is warning message");
  logger.log_error("This is error message");
  
  cout<<"Test finished"<<endl;
  return 0;
}
