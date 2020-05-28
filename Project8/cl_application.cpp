//см. 8.5 методичку
#include "cl_base.h"
#include "cl_class2.h"
#include "cl_application.h"
#include <queue>
#include<iostream>
using namespace std;


cl_application::cl_application() : cl_base::cl_base() {}


void cl_application::bild_tree_objects()
{
	string obj_name;
	cin >> obj_name;
	name = obj_name;
	while (1)
	{
		string parent_name;
		int type, state;
		cl_base* parent_ptr = nullptr, * obj_ptr = nullptr;


		cin >> parent_name;
		if (parent_name == "endtree") break;


		cin >> obj_name >> type >> state;
		switch (type)
		{
		case 2: obj_ptr = new cl_class2(obj_name, state); break;
		case 3: obj_ptr = new cl_class3(obj_name, state); break;
		case 4: obj_ptr = new cl_class4(obj_name, state); break;
		default: break;
		}


		get_child(parent_name)->add_child(obj_ptr);
	}
}


/*void dfs(cl_base* v, int deep)
{
	for (int i = 0; i < deep; i++) cout << " ";
	cout << v->get_name() << endl;
	for (cl_base* child : v->get_children())
		dfs(child, deep + 1);
}
*/

int cl_application::exec_app()
{
	//dfs(this, 0);
	 queue<cl_base*> q;
	q.push(this);
	while (!q.empty())
	{
	cl_base* v = q.front();
	q.pop();
	for (size_t i = 0; i < v->get_children().size(); i++)
	q.push(v->get_children()[i]);


	cout << "The object " << v->get_name() << " is ";
	cout << (v->get_state() > 0 ? "ready" : "not ready") << endl;
	}

	return 0;
}
int cl_application::get_class() { return 1; }