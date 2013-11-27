#include "../src/tidy-helper/tidy_converter.h"

#include <tut/tut.hpp>




namespace tut
{
	struct tidy_data
	{
		tidy_data()
		{
		}
	};

	typedef test_group<tidy_data> tg;
	tg tidy_group("tidy");

	typedef tg::object testobject;


	template<>
	template<>
	void testobject::test<1>()
	{
		set_test_name("Simple tidy");
		string html = "<title>Foo</title><p>Foo!";

		tidy_converter converter;
		string result = converter.convert_xhtml(html);
		
		bool test_value = result.substr(result.length() - 2, 1) == ">";
		ensure_equals("html made tidy", test_value, true);

	}

}
