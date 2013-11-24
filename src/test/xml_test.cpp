#include "../log/log.h"
#include "../xml-helper/xml_helper.h"
#include "../shared/vars.h"


#include <xercesc/util/PlatformUtils.hpp>


#include <xalanc/XPath/XPathEvaluator.hpp>



			XALAN_USING_XERCES(XMLPlatformUtils)

			XALAN_USING_XALAN(XPathEvaluator)


#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

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


int main(int argc, char **argv)
{
  if (argc != 2)
	{
		cout<<"Usage: exectuable xmlfile"<<endl;
		return -1;
	}

  string xml = readfile(argv[1]);

			XMLPlatformUtils::Initialize();

			XPathEvaluator::initialize();

  
  g_verbose = 1;
dataeater::log logger;
   
cout<<"XML Test"<<endl;


  logger.log_info("Initializing");
  string s;
{
  xml_document doc;
  cout<<"Loading doc"<<endl;
  doc.load_xml(xml);
  cout<<"getting node"<<endl;
  xml_nodelist something = doc.select_nodes("/catalog/book");

  for (xml_nodelist::iterator itr=something.begin();itr!=something.end();itr++)
  {
   xml_node node = *itr;  
   xml_node mynode = node.select_single_node("author");
   string text = mynode.get_text();
   cout<<"Node Found Text = "<<text<<endl;
 }
  

}


			XPathEvaluator::terminate();

			XMLPlatformUtils::Terminate();

			

}
