#include "../src/curl-helper/curl_helper.h"
#include "../src/curl-helper/curl_session.h"
#include <tut/tut.hpp>


#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

extern string g_test_datapath;

namespace tut
{
	struct curl_data
	{
		curl_data()
		{
		}
	};

	typedef test_group<curl_data> tg;
	tg curl_group("curl");

	typedef tg::object testobject;


	template<>
	template<>
	void testobject::test<1>()
	{
		set_test_name("Simple Get");		
		string url="http://www.google.com";
		curl_helper curl = curl_helper();

		string str = curl.simple_get(url);
		

		bool test_value = str.length() > 50;

		ensure_equals("page loaded", test_value, true);

	}



	template<>
	template<>
	void testobject::test<2>()
	{
		set_test_name("Simple Session");		
		string url="http://www.google.com";

		curl_session curl;
 
		string str = curl.get(url);

		bool test_value = str.length() > 50;

		ensure_equals("page loaded", test_value, true);

	}



	template<>
	template<>
	void testobject::test<3>()
	{
		set_test_name("Post Session");		
		string url="http://www.github.com";

		curl_session curl;

		form_data data;

		data.add("firstname","Muhammad");
		data.add("lastname", "fahad");

  

		string str = curl.get(url);

		bool test_value = str.length() > 50;

		ensure_equals("page loaded", test_value, true);

		str = curl.post(url, data);

		test_value = str.length() > 30;

		ensure_equals("page loaded", test_value, true);


	}
}
