
#include <xalanc/Include/PlatformDefinitions.hpp>

#include <xalanc/XalanSourceTree/XalanSourceTreeDOMSupport.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeInit.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeParserLiaison.hpp>
#include <xalanc/XPath/NodeRefList.hpp>




#include <xercesc/util/PlatformUtils.hpp>
//#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>



#include <xalanc/PlatformSupport/XSLException.hpp>



#include <xalanc/DOMSupport/XalanDocumentPrefixResolver.hpp>



#include <xalanc/XPath/XObject.hpp>
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
XALAN_USING_XALAN(XObjectPtr)
XALAN_USING_XALAN(NodeRefList)


class xml_nodelist;
class xml_node 
{
 
 private:
  XalanNode* m_pnode;
  shared_ptr<XalanSourceTreeDOMSupport> m_pdom_support;
  shared_ptr<XalanDocumentPrefixResolver> m_pprefix_resolver;

 public:
  xml_node(XalanNode* pnode, shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport);
  virtual ~xml_node();
 public:
  xml_node  select_single_node(string xpath);
  xml_nodelist select_nodes(string xpath);

 public:
  string get_attribute_value(string attribute_name);
  string get_text();
};
class xml_nodelist;
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
  xml_nodelist select_nodes(string xpath);
};

class xml_nodelist
{ 
public:
	class iterator 
	{
		public :
		iterator(xml_nodelist *p_nodelist, size_t start_pos);
		
		xml_node &operator*();
		xml_node *operator->();
		xml_nodelist::iterator &operator++();
		xml_nodelist::iterator operator++(int);
		bool operator==(const xml_nodelist::iterator &rhs);
		bool operator!=(const xml_nodelist::iterator &rhs);
		private:
		void set_current(size_t index);
		xml_nodelist* m_pnodelist;
		shared_ptr<xml_node> m_pnode;
		unsigned int m_pos;
	};

  private:
	const NodeRefList m_nodelist;
	shared_ptr<XalanSourceTreeDOMSupport> m_pdom_support;
	shared_ptr<XalanDocumentPrefixResolver> m_pprefix_resolver;
  public:
	
	xml_nodelist(const XObjectPtr node_list,  shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport);
	xml_node get(size_t index);

	xml_node* get_new(size_t index);
	xml_node operator [](size_t index);
	size_t length();
	xml_nodelist::iterator begin();
	xml_nodelist::iterator end();

 
};

#endif
