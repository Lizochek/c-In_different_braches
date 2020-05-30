#include <iostream>
#include <string>
#include <vector>
#include"cl_base.h"

using namespace std;

cl_base::cl_base(cl_base* head) :head(head) {}
cl_base::cl_base() : head(nullptr) {}

cl_base::cl_base(std::string name, cl_base* head) : name(name), head(head) {}

cl_base::cl_base(std::string name, cl_base* head, int state) : name(name), head(head), state(state) {}

std::string cl_base::get_name() { return name; }

void cl_base::set_name(std::string name) { this->name = name; }

cl_base* const cl_base::get_head() { return head; }

int const cl_base::get_state() { return state; }

void cl_base::set_state(int state) { this->state = state; }

int const cl_base::get_class() { return 0; }

std::vector<cl_base*> cl_base::get_children() { return this->children; }

void cl_base::add_child(cl_base* obj) { children.push_back(obj); }

cl_base*  cl_base::get_child(std::string child_name)
{
    if (this == nullptr)
        return nullptr;
    if (name == child_name) return this;

    for (auto kid : children)
    {
        cl_base* child = kid->get_child(child_name);
        if (child != nullptr) return child;
    }
    return nullptr;
}