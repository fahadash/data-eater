#include "../log/log.h"
#include "xml_helper.h"


#include <xercesc/framework/MemBufInputSource.hpp>

#include <xalanc/Include/PlatformDefinitions.hpp>


#include <xalanc/PlatformSupport/XSLException.hpp>
#include <xalanc/DOMSupport/XalanDocumentPrefixResolver.hpp>

#include <xalanc/XPath/XObject.hpp>
#include <xalanc/XPath/XPathEvaluator.hpp>


#include <xalanc/XalanSourceTree/XalanSourceTreeDOMSupport.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeInit.hpp>
#include <xalanc/XalanSourceTree/XalanSourceTreeParserLiaison.hpp>
#include <xalanc/XalanDOM/XalanDocument.hpp>

#include <iostream>
#include <string>
#include <memory>
using namespace std;

#include<xercesc/util/BinInputStream.hpp>

#include "../shared/util.h"

XALAN_USING_XERCES(XMLPlatformUtils)
XALAN_USING_XERCES(MemBufInputSource)
XALAN_USING_XERCES(BinInputStream)

XALAN_USING_XALAN(XPathEvaluator)

XALAN_USING_XALAN(XalanDocument)
XALAN_USING_XALAN(XalanDocumentPrefixResolver)
XALAN_USING_XALAN(XalanDOMString)
XALAN_USING_XALAN(XalanNode)
XALAN_USING_XALAN(XalanSourceTreeInit)
XALAN_USING_XALAN(XalanSourceTreeDOMSupport)
XALAN_USING_XALAN(XalanSourceTreeParserLiaison)
XALAN_USING_XALAN(XObject)
XALAN_USING_XALAN(XObjectPtr)



  xml_document::xml_document()
  {
//   XMLPlatformUtils::Initialize();
  // XPathEvaluator::initialize();
  }

  xml_document::~xml_document()
  {
   // XPathEvaluator::terminate();
   // XMLPlatformUtils::Terminate();
  }

  xml_node  xml_document::select_single_node(string xpath)
  {
     if (check_null(p_doc, "xml_document - p_doc pointer is null") 
		|| check_null (m_pdom_support, "xml_document - m_pdom_support is null"))
	{
		return xml_node(nullptr, m_pprefix_resolver, shared_ptr<XalanSourceTreeDOMSupport>());
	}
     
     //TODO Check domSupport null

    XPathEvaluator evaluator;
    XalanNode* const theNode = evaluator.selectSingleNode(
							*m_pdom_support,
							p_doc.get(),
							XalanDOMString((const char*) xpath.c_str()).c_str(),

								*m_pprefix_resolver);
	if (theNode == nullptr)
	{
		cout<<"Warning: evaluator.selectSingleNode returned null"<<endl;
	}
	

     return xml_node(theNode, m_pprefix_resolver, m_pdom_support);	
  }

  xml_nodelist xml_document::select_nodes(string xpath)
  {
	XPathEvaluator evaluator;
	XObjectPtr result = 
				evaluator.evaluate(
						*m_pdom_support,
						p_doc.get(),
						XalanDOMString((const char *) xpath.c_str()).c_str(),
						*m_pprefix_resolver);

	return xml_nodelist(result);



  }


  void load(string filepath);
  void xml_document::load_xml(string xml)
  {
	dataeater::log logger;

//	XalanSourceTreeInit		theSourceTreeInit;
	XalanSourceTreeDOMSupport *theDOMSupport = new XalanSourceTreeDOMSupport();
	m_pdom_support.reset(theDOMSupport);
	XalanSourceTreeParserLiaison *theLiaison = new XalanSourceTreeParserLiaison(*theDOMSupport);
	m_pdom_support->setParserLiaison(theLiaison);

	if (theLiaison == nullptr)
	{
		logger.log_warning("Liaison is null");;
	}
	
	//logger.log_info(xml);
//	XalanDOMString input((const char*) xml.c_str());

	const MemBufInputSource *theInputSource = new MemBufInputSource((XMLByte*) xml.c_str(), xml.length(), "doc");

	XalanDocument * const theDocument = theLiaison->parseXMLStream(*theInputSource);
	if (theDocument == nullptr)
	{
		logger.log_warning("XalanDocument in load_xml came back null");
	}
	
	p_doc.reset(theDocument);
	m_pprefix_resolver.reset(new XalanDocumentPrefixResolver(theDocument));

  }

 
 
