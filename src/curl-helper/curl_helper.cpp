
#include "curl_helper.h"
#include "init_curl.h"
#include <string>
#include <sstream>
#include "../log/log.h"
#include <stdlib.h>
#include <string.h>
using namespace std;

curl_helper::curl_helper()
{
	m_curl = init_curl();
}

struct MemoryStruct {
 char *memory;
 size_t size;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
 dataeater::log logger;
 size_t realsize = size * nmemb;
 struct MemoryStruct  *mem = (struct MemoryStruct *) userp;
 mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
 if (mem->memory == NULL)
 {
   logger.log_error("not enough memory (realloc returned NULL)");
 }
 memcpy(&(mem->memory[mem->size]), contents, realsize);
 mem->size += realsize;
 mem->memory[mem->size] = 0;
 
 return realsize;
}

std::string curl_helper::simple_get(std::string url)
{
 string message = "curl_helper::simple_get started: ";
 message.append("url = ");
 message.append(url);
 
 m_logger.log_info(message);
 
 if (m_curl)
 { 
  MemoryStruct chunk;
  chunk.memory = (char*) malloc(1);
  chunk.size = 0;

  m_logger.log_info("Initializing curl options");
  curl_easy_setopt(m_curl, CURLOPT_URL, url.c_str());

  curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1L);

  curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, (void*) &chunk);
  
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
  
  
  return chunk.memory;
 }
 else
 {
  m_logger.log_error("curl was not initialized properly");
  return "";
 }
}

