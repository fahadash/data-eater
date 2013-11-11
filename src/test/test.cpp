#include "../curl-helper/curl_helper.h"

#include <stdio.h>

int main()
{
  curl_helper curl = curl_helper();

  std::string str = curl.simple_get("http://dev.msitakenlypriced.com") ;
  printf(str.c_str());
}
