#ifndef CL_CLASS2 //��. 5.7 ���������
#define CL_CLASS2
#include "cl_base.h"
#include<string>

class cl_class2 :public cl_base
{
public:
    cl_class2(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int get_class()  { return 2; }
};

class cl_class3 : public cl_base
{
public:
    cl_class3(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int get_class()  { return 3; }
};

class cl_class4 :public cl_base
{
public:
    cl_class4(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int get_class() { return 4; }
};
#endif
