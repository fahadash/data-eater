#include "xml_helper.h"



#include <xalanc/Include/PlatformDefinitions.hpp>


#include <xalanc/PlatformSupport/XSLException.hpp>
#include <xalanc/DOMSupport/XalanDocumentPrefixResolver.hpp>

//#include <xalanc/XPath/XObject.hpp>
#include <xalanc/XPath/XPathEvaluator.hpp>


#include <xalanc/XalanSourceTree/XalanSourceTreeDOMSupport.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeInit.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeParserLiaison.hpp>
#include <xalanc/XalanDOM/XalanNode.hpp>
#include "../log/log.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;
XALAN_USING_XALAN(XalanDocument)
XALAN_USING_XALAN(XPathEvaluator)




template <typename T>
inline int check_null(const shared_ptr<T> ptr,const string& message = "Pointer is null")
  {
    if (!ptr)
        {
                cout<<message<<endl;
                return 0;
        }
    return 1;
  }



 xml_node:: xml_node(shared_ptr<XalanNode> pnode, shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport)
 {
  dataeater::log logger;
  logger.log_info("xml_node constructor");
  check_null(pnode, "pnode in xml_node constructor is null");
  m_pnode = pnode;
  m_pdom_support = domSupport;
  m_pprefix_resolver = prefix_resolver;
 }
  xml_node::~xml_node()
  {
   if (m_pnode)
    {
	//TODO: Free up resources
     // m_pnode->release();
    }
  }

  xml_node  xml_node::select_single_node(string xpath)
  {
     dataeater::log logger;
      logger.log_info("select_single_node entrance");

     if (check_null(m_pnode, "xml_node - Pointer is null"))
	{
		return xml_node(shared_ptr<XalanNode>(), m_pprefix_resolver, shared_ptr<XalanSourceTreeDOMSupport>());
	}
     
     //TODO Check domSupport null

	logger.log_info("Evaluation started");
    XPathEvaluator evaluator;
    XalanNode *const theNode = evaluator.selectSingleNode(
							*m_pdom_support,
							m_pnode.get(),
							XalanDOMString((const char*) xpath.c_str()).c_str(),
							*m_pprefix_resolver);

	logger.log_info("Evaluation ended");
	shared_ptr<XalanNode> pnode;
	pnode.reset(theNode);

    return xml_node(pnode, m_pprefix_resolver, m_pdom_support);
											
  }

  list<xml_node> select_nodes(string xpath);

  string get_attribute_value(string attribute_name);
  string xml_node::get_text()
  {
   if (m_pnode)
{
   XalanDOMString str = m_pnode->getNodeName();
   string ret;
   ret.assign(str.begin(), str.end());

   return ret;
}
 else
  {
    cout<<"Error: m_pnode is null";
    return "";
  }
  }

