#include "tidy_converter.h"
#include "../log/log.h"
#include <sstream>
using namespace std;

tidy_converter::tidy_converter(): m_errbuf({0})  
{
	
}

string tidy_converter::convert_xhtml(string input)
{
 log logger;
 TidyBuffer output = {0};
 int rc = -1;
 Bool ok;
 TidyDoc tdoc = tidyCreate();
 
 ok = tidyOptSetBool(tdoc, TidyXhtmlOut, yes);
 
 if (ok)
 {
   rc = tidySetErrorBuffer(tdoc, &m_errbuf);
 }
 else
 {
  logger.log_error("Unable to get positive response for tidyOptSetBool");
 }

 if (rc >= 0)
   rc = tidyParseString(tdoc, input.c_str());

 if (rc >= 0)
   rc = tidyCleanAndRepair(tdoc);

 if (rc >= 0)
   rc = tidyRunDiagnostics(tdoc);

 if (rc > 1)
   rc = tidyOptSetBool(tdoc, TidyForceOutput, yes);
 
 if (rc >= 0)
   rc = tidySaveBuffer(tdoc, &output);

 if (rc >= 0)
  {
   if (rc > 0)
    { 
     // get diagnostic messages m_errbuf.bp
    }
    return (const char *)output.bp;
  }
  else
   {
     stringstream ss;
     ss<<"tidy-Severe error occurred"<<rc;
     logger.log_error(ss.str());
     return "";
    }
   
 
  
}
