#ifndef CL_CLASS5 //��. 5.7 ���������
#define CL_CLASS5
#include "cl_base.h"
#include<string>
class cl_class5 :public cl_base
{
public:
    cl_class5(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 2; }
};
#endif