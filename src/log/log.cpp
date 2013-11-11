#include "log.h"
#include <err.h>
#include <iostream>
#include "../shared/vars.h"

log::log()
{

}
void log::log_error(std::string message)
{
	err(100, message.c_str());
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
	warn(message.c_str());
}

void log::log_error(std::string message, va_list args)
{
 errx(severity, message.c_str(), args);

}

void log::log_warning(std::string message, va_list args)
{
 warnx(message.c_str(), args);
}
