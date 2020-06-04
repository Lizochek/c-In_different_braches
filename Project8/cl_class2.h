#ifndef CL_CLASS2 //см. 5.7 методичку
#define CL_CLASS2
#include "cl_base.h"
#include <string>
#include <iostream>
class cl_class2 :public cl_base
{
public:
    cl_class2(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 2; }
    
    static void signal(std::string& s)  
    {
        s+="class2"+this->get_name();
    }
    static void handler(cl_base* p_ob, std::string& s)  
    {
        std::cout<<"class2 handler s: "<<s<<std::endl;
    }
};

#endif
