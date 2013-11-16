#include "xml_helper.h"



#include <xalanc/Include/PlatformDefinitions.hpp>


#include <xalanc/PlatformSupport/XSLException.hpp>
#include <xalanc/DOMSupport/XalanDocumentPrefixResolver.hpp>

#include <xalanc/XPath/XObject.hpp>
#include <xalanc/XPath/XPathEvaluator.hpp>


#include <xalanc/XalanSourceTree/XalanSourceTreeDOMSupport.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeInit.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeParserLiaison.hpp>


#include <iostream>
#include <string>
#include <memory>
using namespace std;
XALAN_USING_XALAN(XalanDocument)
XALAN_USING_XALAN(XPathEvaluator)

 xml_node:: xml_node(shared_ptr<XalanNode> pnode, shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport)
 {
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
template <typename T> 
inline int check_null(const shared_ptr<T> ptr,const string& message = "Pointer is null")
  {
    if (!ptr)
  	{
		cout<<message;
		return 0;
 	}
    return 1;
  }

  xml_node  xml_node::select_single_node(string xpath)
  {
     if (check_null(m_pnode, "xml_node - Pointer is null"))
	{
		return xml_node(shared_ptr<XalanNode>(), m_pprefix_resolver, shared_ptr<XalanSourceTreeDOMSupport>());
	}
     
     //TODO Check domSupport null

    XPathEvaluator evaluator;
    XalanNode *const theNode = evaluator.selectSingleNode(
							*m_pdom_support,
							m_pnode.get(),
							XalanDOMString((const char*) xpath.c_str()).c_str(),
							*m_pprefix_resolver);

    return xml_node(make_shared<XalanNode>(theNode), m_pprefix_resolver, m_pdom_support);
											
  }

  list<xml_node> select_nodes(string xpath);

  string get_attribute_value(string attribute_name);
  string xml_node::get_text()
  {
   XalanDOMString str = m_pnode->getNodeName();
   string ret;
   ret.assign(str.begin(), str.end());

   return ret;
  }

