#ifndef CL_CLASS3 //см. 5.7 методичку
#define CL_CLASS3
#include "cl_base.h"
#include<string>

class cl_class3 : public cl_base
{
public:
    cl_class3(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int get_class() { return 3; }
};

#endif