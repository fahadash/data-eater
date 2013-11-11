#include <iostream>
using namespace std;
#include "init_curl"


CURL *init_curl()
{
   CURL  *curl = curl_easy_init();

   if (!curl)
 	{
		cout<<"Warning!!! CUrl initialization failed";
	}
  
}
