#include <xalanc/XalanTransformer/XalanTransformer.hpp>
#include <xalanc/XSLT/XSLTResultTarget.hpp>


#include<string>
using namespace std;

#ifndef __xsl_helper_h_included
#define __xsl_helper_h_included

XALAN_USING_XALAN(XalanTransformer)
XALAN_USING_XALAN(XSLTResultTarget)

class xsl_transformer
{
	public:
	
		xsl_transformer(string xslPath);
		
		string transform(string xml);
};

#endif
