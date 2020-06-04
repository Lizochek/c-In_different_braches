#ifndef CL_CLASS3 //см. 5.7 методичку
#define CL_CLASS3
#include "cl_base.h"
#include<string>
class cl_class3 :public cl_base
{
public:
    cl_class3(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 2; }
    
    static void signal(std::string& s)  
    {
        s+="class3"+this->get_name();
    }
    static void handler(cl_base* p_ob, std::string& s)  
    {
        std::cout<<"class3 handler s: "<<s<<std::endl;
    }
};
#endif