#include <xalanc/XalanTransformer/XalanTransformer.hpp>
#include <xalanc/XSLT/XSLTResultTarget.hpp>
#include <xalanc/XSLT/XSLTInputSource.hpp>


#include<string>
using namespace std;

#ifndef __xsl_helper_h_included
#define __xsl_helper_h_included

XALAN_USING_XALAN(XalanTransformer)
XALAN_USING_XALAN(XSLTResultTarget)
XALAN_USING_XALAN(XSLTInputSource)

class xsl_transformer
{
	private:
		XalanTransformer m_transformer;
		XSLTInputSource m_xsl_source;
	public:
	
		xsl_transformer(string xslPath);
		
		string transform(string xml);
};

#endif
