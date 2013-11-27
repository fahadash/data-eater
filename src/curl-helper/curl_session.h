#include <string>
#include <curl/curl.h>
#include "../log/log.h"
#include "../model/form_data.h"

class curl_session
{
 private:
  CURL *m_curl;
  dataeater::log m_logger;
 public:
  std::string get(std::string url);
  std::string post(std::string url, form_data formdata);
 
 public:
  curl_session();
  ~curl_session();
};
