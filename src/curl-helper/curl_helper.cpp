
#include "curl_helper.h"
#include "init_curl.h"
#include <string>
using namespace std;

curl_helper::curl_helper()
{
	m_curl = init_curl();
}

std::string curl_helper::simple_get(std::string url)
{
 string message = "curl_helper::simple_get started: ";
 message.append("url = ");
 message.append(url);
 
 m_logger.log_info(message);
 
 if (m_curl)
 { 
  m_logger.log_info("Initializing curl options");
  curl_easy_setopt(m_curl, CURLOPT_URL, url.c_str());

  curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1L);
  
  m_logger.log_info("Performing curl operation");  

  CURLcode res;
  res  = curl_easy_perform(m_curl);

  if (res != CURLE_OK)
   {
     m_logger.log_error("curl_easy_perform() failed. %s", curl_easy_strerror(res));
	return "";
   }
  
  m_logger.log_info("Cleaning up curl");
  curl_easy_cleanup(m_curl);
  
  return std::string("Curl test goes here\r\n");
 }
 else
 {
  m_logger.log_error("curl was not initialized properly");
  return "";
 }
}

