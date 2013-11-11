#include <string>
#include <curl/curl.h>
#include "../log/log.h"
class curl_helper
{
 private:
  CURL *m_curl;
  log m_logger;
 public:
  std::string simple_get(std::string url);	
 
 public:
  curl_helper();
};
