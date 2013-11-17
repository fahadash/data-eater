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
using namespace std;


int main(int argc, char **argv)
{


			XMLPlatformUtils::Initialize();

			XPathEvaluator::initialize();


  g_verbose = 1;
dataeater::log logger;
   
cout<<"XML Test"<<endl;
  string xml = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>  \r\n <Books><Book ISBN=\"001\" Author=\"Muhammad\" /> <Book ISBN=\"002\" Author=\"Fahad\" />  </Books>";


  logger.log_info("Initializing");
  xml_document doc;
  cout<<"Loading doc";
  doc.load_xml(xml);
  cout<<"getting node";
  xml_node something = doc.select_single_node("/Books/Book[@ISBN='002']/@Author");
  cout<<"getting text";
  string s = something.get_text();

  cout<<"Text = "<<s<<endl;
  cout<<"loaded"<<endl;





			XMLPlatformUtils::Terminate();

			XPathEvaluator::terminate();

}
