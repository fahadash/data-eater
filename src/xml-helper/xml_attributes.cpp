#include "xml_helper.h"
#include "../log/log.h"
#include <sstream>
#include <iostream>
using namespace std;

#include <xalanc/XPath/XObject.hpp>
#include <xalanc/XalanDOM/XalanNamedNodeMap.hpp>



XALAN_USING_XALAN(XObjectPtr)

XALAN_USING_XALAN(XObject)

XALAN_USING_XALAN(XalanNamedNodeMap)

xml_attributes::xml_attributes(const XalanNamedNodeMap* map,  shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport) : m_map(map)
{
	m_pdom_support = domSupport;
	m_pprefix_resolver = prefix_resolver;
}


size_t xml_attributes::length()
{
	return m_map->getLength();
}

xml_node xml_attributes::get(size_t index)
{
	if (index >= length())
	{
		throw std::string("out of bounds");
	}
	XalanNode *pnode = m_map->item(index);
	return xml_node(pnode, m_pprefix_resolver, m_pdom_support);
}

xml_node* xml_attributes::get_new(size_t index)
{
	if (index >= length())
	{
		return nullptr;
	}

	return new xml_node(m_map->item(index), m_pprefix_resolver, m_pdom_support);
}
xml_node xml_attributes::operator [](size_t index)
{
	return get(index);
}



//iterator stuff
//


xml_attributes::iterator xml_attributes::begin()
{
	return iterator(this, 0);
}

xml_attributes::iterator xml_attributes::end()
{
	return iterator(this, length());
}


xml_attributes::iterator::iterator(xml_attributes *p_attributes, size_t start_pos) : m_pattributes(p_attributes), m_pos(start_pos)
{
	size_t length = p_attributes->length();
	if (start_pos < length) 
	{
		set_current(start_pos);
	}
	else
	{
		start_pos = length;
	}
}

void xml_attributes::iterator::set_current(size_t index)
{
	m_pnode.reset(m_pattributes->get_new(index));
}

xml_node &xml_attributes::iterator::operator*()
{
	return (*m_pnode);
}

xml_node *xml_attributes::iterator::operator->()
{
	return m_pnode.get();
}

xml_attributes::iterator& xml_attributes::iterator::operator++()
{
	set_current(++m_pos);
	return *this;
}
xml_attributes::iterator xml_attributes::iterator::operator++(int)
{
	xml_attributes::iterator itr(*this);
	++(*this);
	return itr;
}
bool xml_attributes::iterator::operator==(const xml_attributes::iterator &rhs)
{
	return (this->m_pos == rhs.m_pos);
}
bool xml_attributes::iterator::operator!=(const xml_attributes::iterator &rhs)
{
	return (this->m_pos != rhs.m_pos);
}
