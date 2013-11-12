#include "form_data.h"


void form_data::add(string key, string value)
  {
    Key_Value_Pair pair;
    pair.key = key;
    pair.value = value;
    m_data.push_back(pair);
  }


 curl_httppost * form_data::curl_form_data()
 {
   curl_httppost *formpost = NULL;
   curl_httppost *lastptr = NULL;
   for (vector<Key_Value_Pair>::iterator itr = m_data.begin(); itr != m_data.end(); ++itr)
   {
     Key_Value_Pair &pair = *itr;
     curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, pair.key.c_str(), CURLFORM_COPYCONTENTS, pair.value.c_str(), CURLFORM_END);

   }
   return formpost;
 }

