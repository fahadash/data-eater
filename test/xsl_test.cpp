#include "../src/xml-helper/xsl_helper.h"
#include <tut/tut.hpp>
#include "test_util.h"


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
		set_test_name("Simple Transform");

		xsl_transformer transformer(g_test_datapath + "/simple.xsl");
		string test_value = transformer.transform(xml);

		ensure_equals("transformation value equals", test_value, "success");

	}

}
