#include "../shared/vars.h"
#include "../shared/args.h"
#include<string>


#ifndef __class_log_defined
#define __class_log_defined
namespace dataeater
{
class log
{
	private:


	public:
	log();

	void log_error(std::string message);
	void log_info(std::string message);
	void log_warning(std::string message);
 
	void log_error(std::string message, std::string arg0);
 	void log_warning(std::string message, std::string  args0);

	
};
}
#endif
