#include "xml_helper.h"
#include "../log/log.h"
#include <sstream>
#include <iostream>
using namespace std;

#include <xalanc/XPath/XObject.hpp>
#include <xalanc/XPath/NodeRefList.hpp>



XALAN_USING_XALAN(XObjectPtr)

XALAN_USING_XALAN(XObject)

XALAN_USING_XALAN(NodeRefList)

xml_nodelist::xml_nodelist(const XObjectPtr node_list,  shared_ptr<XalanDocumentPrefixResolver> prefix_resolver, shared_ptr<XalanSourceTreeDOMSupport> domSupport) : m_nodelist(node_list->nodeset())
{

	m_pdom_support = domSupport;
	m_pprefix_resolver = prefix_resolver;
}


size_t xml_nodelist::length()
{
	return m_nodelist.getLength();
}

xml_node xml_nodelist::get(size_t index)
{
	if (index >= length())
	{
		throw std::string("out of bounds");
	}
	return xml_node(m_nodelist.item(index), m_pprefix_resolver, m_pdom_support);
}

xml_node* xml_nodelist::get_new(size_t index)
{
	if (index >= length())
	{
		return nullptr;
	}

	return new xml_node(m_nodelist.item(index), m_pprefix_resolver, m_pdom_support);
}
xml_node xml_nodelist::operator [](size_t index)
{
	return get(index);
}



//iterator stuff
//


xml_nodelist::iterator xml_nodelist::begin()
{
	return iterator(this, 0);
}

xml_nodelist::iterator xml_nodelist::end()
{
	return iterator(this, length()-1);
}


xml_nodelist::iterator::iterator(xml_nodelist *p_nodelist, size_t start_pos) : m_pnodelist(p_nodelist), m_pos(start_pos)
{
	set_current(start_pos);
}

void xml_nodelist::iterator::set_current(size_t index)
{
	m_pnode.reset(m_pnodelist->get_new(index));
}

xml_node xml_nodelist::iterator::operator*()
{
	return (*m_pnode);
}

xml_node *xml_nodelist::iterator::operator->()
{
	return m_pnode.get();
}

xml_nodelist::iterator& xml_nodelist::iterator::operator++()
{
	set_current(++m_pos);
	return *this;
}
xml_nodelist::iterator xml_nodelist::iterator::operator++(int)
{
	xml_nodelist::iterator itr(*this);
	++(*this);
	return itr;
}
bool xml_nodelist::iterator::operator==(const xml_nodelist::iterator &rhs)
{
	return (this->m_pnode == rhs.m_pnode);
}
bool xml_nodelist::iterator::operator!=(const xml_nodelist::iterator &rhs)
{
	return (this->m_pnode != rhs.m_pnode);
}
