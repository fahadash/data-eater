#include "test_util.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

string readfile(string filename)
{
  stringstream output;
  string line;
  ifstream myfile(filename);
  if (myfile.is_open())
   {
    while (getline(myfile, line))
	{
		output<<line<<endl;
	}
	myfile.close();
   }
	else
	{
		cerr<<"Error: could not open file:"<<filename;
	}
	
	return output.str();
}
