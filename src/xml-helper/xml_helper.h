
#include <xalanc/Include/PlatformDefinitions.hpp>

#include <xalanc/XalanSourceTree/XalanSourceTreeDOMSupport.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeInit.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeParserLiaison.hpp>




#include <xercesc/util/PlatformUtils.hpp>
//#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>



#include <xalanc/PlatformSupport/XSLException.hpp>



#include <xalanc/DOMSupport/XalanDocumentPrefixResolver.hpp>



//#include <xalanc/XPath/XObject.hpp>
#include <xalanc/XPath/XPathEvaluator.hpp>

#include <string>
#include <list>
#include <memory>
using namespace std;

#ifndef __xml_helper_h_included
#define __xml_helper_h_included


XALAN_USING_XALAN(XalanDocument)
XALAN_USING_XALAN(XalanNode)
XALAN_USING_XALAN(XalanSourceTreeDOMSupport)
XALAN_USING_XALAN(XalanDocumentPrefixResolver)
XALAN_USING_XALAN(XalanDOMString)


class xml_node 
{
 
 private:
  shared_ptr<XalanNode> m_pnode;
  shared_ptr<XalanSourceTreeDOMSupport> m_pdom_support;
  shared_ptr<XalanDocumentPrefixResolver> m_pprefix_resolver;

 public:
  xml_node(shared_ptr<XalanNode> pnode, shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport);
  virtual ~xml_node();
 public:
  xml_node  select_single_node(string xpath);
  list<xml_node> select_nodes(string xpath);

 public:
  string get_attribute_value(string attribute_name);
  string get_text();
};

class xml_document
{
 private:
  shared_ptr<XalanDocument> p_doc;
  shared_ptr<XalanSourceTreeDOMSupport> m_pdom_support;
  shared_ptr<XalanDocumentPrefixResolver> m_pprefix_resolver;
 public:
  xml_document();
  virtual ~xml_document();
  
 public:
  void load(string filepath);
  void load_xml(string xml);
 public:
  xml_node select_single_node(string xpath);
  list<xml_node> select_nodes(string xpath);
};

#endif
