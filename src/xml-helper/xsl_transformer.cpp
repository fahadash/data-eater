#include "xsl_helper.h"
#include <string>
#include <sstream>
using namespace std;




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
