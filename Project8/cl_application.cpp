#include "cl_base.h"
#include "cl_class2.h"
#include "cl_class3.h"
#include "cl_class4.h"
#include "cl_class5.h"
#include "cl_class6.h"
#include "cl_application.h"
#include <queue>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

cl_application::cl_application() : cl_base::cl_base() {}

void cl_application::bild_tree_objects()
{
    string obj_name;
    cin >> obj_name;
    name = obj_name;
    state = 1;
    while (1)
    {
        string path;
        int type, state;
        cl_base* parent_ptr = nullptr, * obj_ptr = nullptr;


        cin >> path;
        if (path == "endtree") break;
        cin>> obj_name;
        parent_ptr = this->get_from_tree(path);
        #ifdef DEBUG cout << parent_ptr << endl;
        #endif
        if (parent_ptr == nullptr) break;

        cin >> type >> state;
        switch (type)
        {
        case 2:
            obj_ptr = new cl_class2(obj_name, state);
            break;
        case 3:
            obj_ptr = new cl_class3(obj_name, state);
            break;
        case 4:
            obj_ptr = new cl_class4(obj_name, state);
            break;
        case 5:
            obj_ptr = new cl_class5(obj_name, state);
            break;
        case 6:
            obj_ptr = new cl_class6(obj_name, state);
            break;
        default: break;
        }
        obj_ptr->set_name(obj_name);
        parent_ptr->add_child(obj_ptr);
    }
}

void dfs(cl_base* v, int deep)
{
    for (int i = 0; i < deep; i++) cout << '\t';
    cout << v->get_name() << endl;
    for (cl_base* child : v->get_children())
        dfs(child, deep + 1);
}

int  cl_application::exec_app()
{
    cout << "Object tree" << endl;
    dfs(this, 0);
    string path;
    cin >> path;
    while (path != "//")
    {
        cl_base* obj_ptr;
        obj_ptr = this->get_from_tree(path);
        cout << path << " ";
        if (obj_ptr == nullptr)
            cout << "Object not found" << endl;
        else
            cout << "Object name: " << obj_ptr->get_name() << endl;
        cin >> path;
    }
    return 0;
}
int const  cl_application::get_class() { return 1; }