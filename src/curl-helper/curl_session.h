#include <string>
#include <curl/curl.h>
#include "../log/log.h"
class curl_session
{
 private:
  CURL *m_curl;
  log m_logger;
 public:
  std::string get(std::string url);
  std::string post(std::string url, std::string formdata);
 
 public:
  curl_session();
};
