#include "../src/log/log.h"

#include <tut/tut.hpp>



namespace tut
{
	struct log_data
	{
		log_data()
		{
		}
	};

	typedef test_group<log_data> tg;
	tg log_group("log");

	typedef tg::object testobject;


	template<>
	template<>
	void testobject::test<1>()
	{
		set_test_name("information");
		dataeater::log logger;
		logger.log_info("info");
				
	}


	template<>
	template<>
	void testobject::test<2>()
	{
		set_test_name("warning");
		dataeater::log logger;
		logger.log_warning("test-warning");
				
	}


	template<>
	template<>
	void testobject::test<3>()
	{
		set_test_name("error");
		dataeater::log logger;
		logger.log_error("test-error");
				
	}

}
