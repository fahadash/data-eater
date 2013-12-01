#include "xsl_helper.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include <xalanc/XalanDOM/XalanDOMString.hpp>


XALAN_USING_XALAN(XalanDOMString)




xsl_transformer::xsl_transformer(string xslPath) : m_xsl_source(xslPath.c_str())
{
  //Initialize xerces/xalan here

}

string xsl_transformer::transform(string xml)
{
	stringstream stream;

	XSLTResultTarget target(stream);
	istringstream input(xml);

 	XSLTInputSource source(input);

	m_transformer.transform(source, m_xsl_source, target);
	return stream.str();
}


void xsl_transformer::set_stylesheet_param(string param_name, string param_value)
{
	m_transformer.setStylesheetParam(XalanDOMString(param_name.c_str()), XalanDOMString(param_value.c_str()));
}

//Xalan 1.11 is required. 1.10 does not have double support for 
// XalanTransformer::setStylesheetParam()
void xsl_transformer::set_stylesheet_param(string param_name, double param_value)
{
	m_transformer.setStylesheetParam(param_name.c_str(), param_value);
}
