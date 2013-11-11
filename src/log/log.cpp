#include "log.h"
#include <err.h>

log::log(int verbose=0) : m_verbose(verbose)
{
|

void log::error(std::string message, int severity  = 100)
{
	err(severity, message.c_str());
}

void log::info(std::string message)
{
	std::cout<<"info: "<<message<<endl;
}

void log::warning(std::string message)
{
	warn(message);
}


