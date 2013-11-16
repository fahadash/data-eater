#include "xml_helper.h"


#include <xercesc/framework/MemBufInputSource.hpp>

#include <xalanc/Include/PlatformDefinitions.hpp>


#include <xalanc/PlatformSupport/XSLException.hpp>
#include <xalanc/DOMSupport/XalanDocumentPrefixResolver.hpp>

//#include <xalanc/XPath/XObject.hpp>
#include <xalanc/XPath/XPathEvaluator.hpp>


#include <xalanc/XalanSourceTree/XalanSourceTreeDOMSupport.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeInit.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeParserLiaison.hpp>
#include <xalanc/XalanDOM/XalanDocument.hpp>

#include <iostream>
#include <string>
#include <memory>
using namespace std;

XALAN_USING_XERCES(XMLPlatformUtils)
XALAN_USING_XERCES(MemBufInputSource)


XALAN_USING_XALAN(XPathEvaluator)

XALAN_USING_XALAN(XalanDocument)
XALAN_USING_XALAN(XalanDocumentPrefixResolver)
XALAN_USING_XALAN(XalanDOMString)
XALAN_USING_XALAN(XalanNode)
XALAN_USING_XALAN(XalanSourceTreeInit)
XALAN_USING_XALAN(XalanSourceTreeDOMSupport)
XALAN_USING_XALAN(XalanSourceTreeParserLiaison)
//XALAN_USING_XALAN(XObjectPtr)

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

  xml_document::xml_document()
  {
   XMLPlatformUtils::Initialize();
   XPathEvaluator::initialize();
  }

  xml_document::~xml_document()
  {
    XPathEvaluator::terminate();
    XMLPlatformUtils::Terminate();
  }

  xml_node  xml_document::select_single_node(string xpath)
  {
     if (check_null(p_doc, "xml_document - Pointer is null"))
	{
		return xml_node(shared_ptr<XalanNode>(), m_pprefix_resolver, shared_ptr<XalanSourceTreeDOMSupport>());
	}
     
     //TODO Check domSupport null

    XPathEvaluator evaluator;
    XalanNode* const theNode = evaluator.selectSingleNode(
							*m_pdom_support,
							p_doc.get(),
							XalanDOMString((const char*) xpath.c_str()).c_str(),
							*m_pprefix_resolver);

	shared_ptr<XalanNode> pnode;
	pnode.reset(theNode);    
    return xml_node(pnode, m_pprefix_resolver, m_pdom_support);
											
  }

  list<xml_node> select_nodes(string xpath);


  void load(string filepath);
  void xml_document::load_xml(string xml)
  {
	XalanSourceTreeInit		theSourceTreeInit;
	XalanSourceTreeDOMSupport *theDOMSupport = new XalanSourceTreeDOMSupport();
 	m_pdom_support.reset(theDOMSupport);
	XalanSourceTreeParserLiaison *theLiaison = new XalanSourceTreeParserLiaison(*theDOMSupport);
	m_pdom_support->setParserLiaison(theLiaison);

	XalanDOMString input((const char*) xml.c_str());

	const MemBufInputSource theInputSource((XMLByte*) input.c_str(), input.length(), "doc");

	XalanDocument * const theDocument = theLiaison->parseXMLStream(theInputSource);

	p_doc.reset(theDocument);
	m_pprefix_resolver.reset(new XalanDocumentPrefixResolver(theDocument));

  }

 
 
