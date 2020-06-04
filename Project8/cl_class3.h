#ifndef CL_CLASS3 //��. 5.7 ���������
#define CL_CLASS3
#include "cl_base.h"
#include<string>
class cl_class3 :public cl_base
{
public:
    cl_class3(std::string name, int state) : cl_base::cl_base(name, nullptr, state) {}
    int const get_class() override { return 3; }
    
    static void signal(std::string& s)  
    {
    }
    static void handler(cl_base* p_ob, std::string& s)  
    {
        std::cout<<std::endl<<"Signal to "<<p_ob->get_name()<<" Text: "<<s;
    }
};
#endif