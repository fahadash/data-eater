#include "../src/xml-helper/xml_helper.h"

#include <tut/tut.hpp>


#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

extern string g_test_datapath;
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
	struct xml_data
	{
		string xml;
		xml_data()
		{
			xml = readfile(g_test_datapath + "/test.xml");
		}
	};

	typedef test_group<xml_data> tg;
	tg xml_group("xml");

	typedef tg::object testobject;


	template<>
	template<>
	void testobject::test<1>()
	{
		set_test_name("Simple Load");
		
		
		XMLPlatformUtils::Initialize();
		XPathEvaluator::initialize();

		{
			xml_document doc;
			
			doc.load_xml(xml);
		}
		
		XPathEvaluator::terminate();
		XMLPlatformUtils::Terminate();


		ensure_equals("Loaded", 1, 1);

	}

	template<>
	template<>
	void testobject::test<2>()
	{
		set_test_name("Testing select_single_node");
		
		string test_value;
		XMLPlatformUtils::Initialize();
		XPathEvaluator::initialize();

		{
			xml_document doc;
			
			doc.load_xml(xml);
			
			xml_node node = doc.select_single_node("//book/author");
			test_value = node.get_name();
		}
		
		XPathEvaluator::terminate();
		XMLPlatformUtils::Terminate();


		ensure_equals("names are matching", test_value, "author");

	}

	template<>
	template<>
	void testobject::test<3>()
	{
		set_test_name("testing node list");
		
		int test_value;
		XMLPlatformUtils::Initialize();
		XPathEvaluator::initialize();

		{
			xml_document doc;
			
			doc.load_xml(xml);
			
			xml_nodelist nodes = doc.select_nodes("//book");
			test_value = nodes.length();
		}
		
		XPathEvaluator::terminate();
		XMLPlatformUtils::Terminate();


		ensure_equals("names are matching", test_value, 12);

	}


	template<>
	template<>
	void testobject::test<4>()
	{
		set_test_name("single node attribute");
		
		bool test_value;
		XMLPlatformUtils::Initialize();
		XPathEvaluator::initialize();

		{
			xml_document doc;
			
			doc.load_xml(xml);
			
			xml_node node = doc.select_single_node("//book");
			
			string attribute = node.get_attribute_value("id");
			
			test_value = attribute.length() > 0;
		}
		
		XPathEvaluator::terminate();
		XMLPlatformUtils::Terminate();


		ensure_equals("names are matching", test_value, true);

	}


	template<>
	template<>
	void testobject::test<5>()
	{
		set_test_name("single node attribute-list");
		
		bool test_value;
		XMLPlatformUtils::Initialize();
		XPathEvaluator::initialize();

		{
			xml_document doc;
			
			doc.load_xml(xml);
			
			xml_node node = doc.select_single_node("//book");
			
			xml_attributes attributes = node.get_attributes();
			
			test_value = attributes.length() > 0;
		}
		
		XPathEvaluator::terminate();
		XMLPlatformUtils::Terminate();


		ensure_equals("names are matching", test_value, true);

	}
}
