
#include <iostream>
#include <string>
#include <vector>
#include"cl_base.h"

using namespace std;

cl_base::cl_base(cl_base* head) :head(head) {}
cl_base::cl_base() : head(nullptr) {}

cl_base::cl_base(std::string name, cl_base* head) : name(name), head(head) {}

cl_base::cl_base(std::string name, cl_base* head, int state) : name(name), head(head), state(state) {}

std::string const cl_base::get_name() { return name; }

void cl_base::set_name(std::string name) { this->name = name; }

cl_base* const cl_base::get_head() { return head; }

int const cl_base::get_state() { return state; }


void cl_base::set_state(int state) { this->state = state; }

int const cl_base::get_class() { return 0; }


std::list<cl_base*> cl_base::get_children() { return this->children; }

void cl_base::add_child(cl_base* obj) { children.push_back(obj); }

cl_base* const cl_base::get_child(std::string child_name)
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

cl_base* cl_base::get_from_tree(string path)
{
	string sub_path, cur_obj_name;
	int count_of_sleshes = 0;
	int ptr = 1;//указатель на конец имени текущего узла
	while (count_of_sleshes < 1 && ptr < path.size())
		if (path[ptr++] == '/') count_of_sleshes++;
#ifdef DEBUG 
	cout << path.substr(1, ptr - (ptr == path.size() ? 1 : 2)) << " " << count_of_sleshes << " " << ptr << endl;
#endif
	if (ptr == 1) return nullptr;//строка пуста€
	cur_obj_name = path.substr(1, ptr - (ptr == path.size() ? 1 : 2));//им€ текущего узла
	if (cur_obj_name != this->get_name()) return nullptr;//проверка на совпадение с именем объекта
	if (!count_of_sleshes)//если мы добрались до конечного узла
		return this;//это и есть искомый объект!

	sub_path = path.substr(ptr - 1);//извлекаем оставшийс€ путь
	for (cl_base* child : this->get_children())//перебираем потомков текущего узла
	{
		cl_base* sub_ans = child->get_from_tree(sub_path);
		if (sub_ans != nullptr) return sub_ans;
	}
	return nullptr;
	// /root/objname1/objname2/objnameN 
	// /objname2/objnameN
	// /objnameN 
}