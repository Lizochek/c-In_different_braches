
#ifndef CL_CLASS2 //см. 5.7 методичку
#define CL_CLASS2
#include "cl_base.h"
#include<string>
class cl_class2 :public cl_base
{
public:
    cl_class2(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 2; }
};

class cl_class3 : public cl_base
{
public:
    cl_class3(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 3; }
};

class cl_class4 :public cl_base
{
public:
    cl_class4(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 4; }

};
class cl_class5 :public cl_base
{
public:
    cl_class5(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 5; }
};
class cl_class6 :public cl_base
{
public:
    cl_class6(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 6; }
};

#endif
