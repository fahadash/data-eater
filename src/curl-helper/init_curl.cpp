#include <iostream>
using namespace std;
#include "init_curl.h"
#include "../log/log.h"

CURL *init_curl()
{
   
   dataeater::log logger;
   logger.log_info("Initializing curl easy");
   CURL  *curl = curl_easy_init();  
  
   if (!curl)
 	{
		logger.log_warning("Warning!!! CUrl initialization failed");
	}

	return curl;
  
}
