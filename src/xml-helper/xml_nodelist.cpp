#include "xml_helper.h"
#include "../log/log.h"
#include <sstream>
using namespace std;

#include <xalanc/XPath/XObject.hpp>



XALAN_USING_XALAN(XObjectPtr)

XALAN_USING_XALAN(XObject)

xml_nodelist::xml_nodelist(XObjectPtr node_list)
{
	dataeater::log logger;
	if (node_list->getType() == XObject::eTypeNodeSet)
	{
		logger.log_info("Hello node list");
		m_nodelist = node_list;
		stringstream stm;

		stm<<"The length is..."<<m_nodelist->nodeset().getLength();
		logger.log_info(stm.str());
	}
	else
	{
		logger.log_error("nodelist is of invalid type");	
	}
}
