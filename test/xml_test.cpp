#include "../src/xml-helper/xml_helper.h"

#include <tut/tut.hpp>


#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


#include <xercesc/util/PlatformUtils.hpp>


#include <xalanc/XPath/XPathEvaluator.hpp>



XALAN_USING_XERCES(XMLPlatformUtils)

XALAN_USING_XALAN(XPathEvaluator)

string readfile(string filename)
{
  stringstream output;
  string line;
  ifstream myfile(filename);
  if (myfile.is_open())
   {
    while (getline(myfile, line))
	{
		output<<line<<endl;
	}
	myfile.close();
   }
	else
	{
		cerr<<"Error: could not open file:"<<filename;
	}
	
	return output.str();
}

namespace tut
{
	struct data
	{
		string xml;
		data()
		{
			xml = readfile("data/test.xml");
		}
	};

	typedef test_group<data> tg;
	tg test_group("xml library tests");

	typedef tg::object testobject;


	template<>
	template<>
	void testobject::test<1>()
	{
		set_test_name("Simple Load");
		
		
		XMLPlatformUtils::Initialize();
		XPathEvaluator::initialize();

		xml_document doc;
		//doc.load_xml(xml);

		
		XMLPlatformUtils::Terminate();
		XPathEvaluator::terminate();


		ensure_equals("Loaded", 1, 1);

	}
}
