#include "log.h"
#include <err.h>
#include <iostream>
using namespace std;
#include "../shared/vars.h"


namespace dataeater
{
log::log()
{

}
void log::log_error(std::string message)
{
	cout<<message.c_str();
}

void log::log_info(std::string message)
{
	if (g_verbose == 1)
	{
		std::cout<<"info: "<<message<<std::endl;
	}
}

void log::log_warning(std::string message)
{
	cout<<message.c_str()<<endl;
}

void log::log_error(std::string message, std::string arg0)
{
 errx(100, (const char *)message.c_str(), arg0.c_str());

}

void log::log_warning(std::string message, std::string arg0)
{
 warnx( (const char *)message.c_str(), arg0.c_str());
}
}
