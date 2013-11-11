#include<string>

class log
{
	private:


	public:
	log();

	void log_error(std::string message);
	void log_info(std::string message);
	void log_warning(std::string message);
 
	void log_error(std::string message, va_list args);
 	void log_warning(std::string message, va_list args);

	
};
