#include "../src/xml-helper/xsl_helper.h"
#include <tut/tut.hpp>
#include "test_util.h"
#include <xalanc/PlatformSupport/XSLException.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>

#include <xalanc/Include/PlatformDefinitions.hpp>
#include <xalanc/XPath/XPathEvaluator.hpp>


XALAN_USING_XERCES(XMLPlatformUtils)
XALAN_USING_XALAN(XPathEvaluator)
XALAN_USING_XALAN(XSLException)

extern string g_test_datapath;



namespace tut
{
	struct xsl_data
	{
		string xml;
		xsl_data()
		{
			xml = readfile(g_test_datapath + "/test.xml");
		}
	};

	typedef test_group<xsl_data> tg;
	tg xsl_group("xsl");

	typedef tg::object testobject;


	template<>
	template<>
	void testobject::test<1>()
	{
		
		XMLPlatformUtils::Initialize();	
	        XalanTransformer::initialize();
		{
			try
			{
				set_test_name("Simple Transform");

				xsl_transformer transformer(g_test_datapath + "/simple_test.xsl");

				string test_value = transformer.transform(xml);

				ensure_equals("transformation value equals", test_value, "success");
			}
			catch (const XSLException& ex)
			{
				cerr<< "XSL exception: "
					<<ex.getMessage()
					<<endl;
				fail("xsl exception occured");
			}
		}	
	        XalanTransformer::terminate();
		XMLPlatformUtils::Terminate();

	}

}
