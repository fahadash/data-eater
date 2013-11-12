#include <curl/curl.h>
#include <vector>
#include <string>

using namespace std;

struct Key_Value_Pair
{
 string key;
 string value;
};

class form_data
{
 private:
  vector<Key_Value_Pair> m_data;

 public:
  void add(string key, string value);
 
 curl_httppost *get_curl_data();
 

};
