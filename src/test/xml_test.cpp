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
  string xml = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>  \r\n <Books><Book ISBN=\"001\" Author=\"Muhammad\" >Good Deeds</Book> <Book ISBN=\"002\" Author=\"Fahad\" />  </Books>";


  logger.log_info("Initializing");
  string s;
{
  xml_document doc;
  cout<<"Loading doc";
  doc.load_xml(xml);
  cout<<"getting node";
  xml_nodelist something = doc.select_nodes("/Books/Book");

  for (xml_nodelist::iterator itr=something.begin();itr!=something.end();itr++)
  {
   xml_node node = *itr;
   cout<<"Length = "<<something.length()<<endl;
  
   string text = node.get_text();

   cout<<"Text = "<<text<<endl;
 }
  

}
  cout<<"loaded"<<endl;



			XPathEvaluator::terminate();

			XMLPlatformUtils::Terminate();

			

}
