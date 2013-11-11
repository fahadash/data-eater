#include<string>

class log
{
	private:
	int m_verbose;

	public:
	log(int verbose = 0);

	void log_error(std::string message, int severity = 100);
	void log_info(std::string message);
	void log_warning(std::string message);
 
	void log_error(std::string message, int severity = 100, va_list args);
 	void log_warning(std::string message, va_list args);

	
};
