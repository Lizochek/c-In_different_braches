#ifndef CL_CLASS4 //��. 5.7 ���������
#define CL_CLASS4
#include "cl_base.h"
#include<string>

class cl_class4 :public cl_base
{
public:
    cl_class4(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 4; }
};

#endif