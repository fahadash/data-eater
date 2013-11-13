#include <sstream>
#include "form_data.h"
#include "../log/log.h"

using namespace std;

void form_data::add(string key, string value)
  {
    Key_Value_Pair pair;
    pair.key = key;
    pair.value = value;
    m_data.push_back(pair);
  }


 curl_httppost * form_data::curl_form_data()
 {
   log logger;
   logger.log_info("Building curl form data");

   curl_httppost *formpost = NULL;
   curl_httppost *lastptr = NULL;
   for (vector<Key_Value_Pair>::iterator itr = m_data.begin(); itr != m_data.end(); ++itr)
   {
     Key_Value_Pair &pair = *itr;
     stringstream ss;
     ss<<"Building form field"<<pair.key<<"="<<pair.value;
     logger.log_info(ss.str());    
     curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, pair.key.c_str(), CURLFORM_COPYCONTENTS, pair.value.c_str(), CURLFORM_END);

   }
   return formpost;
 }

