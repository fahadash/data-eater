#include<memory>
#include <string>
#include <iostream>
using namespace std;

#ifndef __util_h_included
#define __util_h_included


#include <iostream>
using namespace std;

template <typename T>
inline int check_null(const shared_ptr<T> ptr,const string& message)
  {
    if (!ptr)
        {
                cout<<message<<endl;
                return 1;
        }
    return 0;
  }


inline int check_null(void* ptr,const string& message)
  {
    if (ptr == nullptr)
        {
                cout<<message<<endl;
                return 1;
        }
    return 0;
  }

#endif
