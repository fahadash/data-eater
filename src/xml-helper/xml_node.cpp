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

#include "../shared/util.h"

XALAN_USING_XALAN(XalanDocument)
XALAN_USING_XALAN(XPathEvaluator)




 xml_node:: xml_node(XalanNode* pnode, shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport)
 {
  dataeater::log logger;
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
     if (check_null(m_pnode, "xml_document - p_doc pointer is null") 
		|| check_null (m_pdom_support, "xml_document - m_pdom_support is null"))
	{
		return xml_node(nullptr, m_pprefix_resolver, shared_ptr<XalanSourceTreeDOMSupport>());
	}
     
     //TODO Check domSupport null

    XPathEvaluator evaluator;
    XalanNode* const theNode = evaluator.selectSingleNode(
							*m_pdom_support,
							m_pnode,
							XalanDOMString((const char*) xpath.c_str()).c_str(),

								*m_pprefix_resolver);
	if (theNode == nullptr)
	{
		cout<<"Warning: evaluator.selectSingleNode returned null"<<endl;
	}
	

     return xml_node(theNode, m_pprefix_resolver, m_pdom_support);	
  }

  xml_nodelist xml_node::select_nodes(string xpath)
  {
	XPathEvaluator evaluator;
	const XObjectPtr result(
				evaluator.evaluate(
						*m_pdom_support,
						m_pnode,
						XalanDOMString((const char *) xpath.c_str()).c_str(),
						*m_pprefix_resolver));

	return xml_nodelist(result, m_pprefix_resolver, m_pdom_support);

  }

  string get_attribute_value(string attribute_name);
  string xml_node::get_text()
  {
	if (m_pnode)
	{
		XalanNode *ptarget_node = m_pnode;

		if (m_pnode->getNodeType() == XalanNode::ELEMENT_NODE)
		{
			if ((ptarget_node = m_pnode->getFirstChild()) == nullptr)
			{
				return "";
			}
		}
		XalanDOMString str = ptarget_node->getNodeValue();
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

