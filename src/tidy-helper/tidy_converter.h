#include <tidy/tidy.h>
#include <tidy/buffio.h>
#include <errno.h>
#include <string>
using namespace std;

class tidy_converter
{
  private:
   TidyBuffer m_errbuf;   
  public:
   tidy_converter();

  public:
   string convert_xhtml(string input);
   
   
};
