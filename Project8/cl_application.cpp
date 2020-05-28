
#include "cl_base.h"
#include "cl_class2.h"
#include "cl_application.h"
#include <queue>
#include<iostream>
#include <algorithm>
#include <list>
using namespace std;

cl_application::cl_application() : cl_base::cl_base() {}

void cl_application::bild_tree_objects()
{
    string obj_name;
    cin >> obj_name;
    name = obj_name;
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

std::vector<std::string> cl_application::get_horizontal_ordered_hierarchy(cl_application* root) {
    std::queue <cl_base*> members;                                              // создаем новую очередь
    std::vector<std::string> hierarchy;                                         // об€вл€ем список, в который будет записана иерахи€
    members.push(root);                                                         // добавл€ем в очередь корневой элемент, дальнеейшее обращение через элементы очереди
    while (!members.empty()) {                                                  // то есть пока не просмотрены все уровни иерархии
        std::list<cl_base*>slaves = (members.front())->get_children();                  // список подчиненных объектов экземпл€ра
                                                                                // IBase на рассматриваемом уровне иерархии
        if (!slaves.empty()) {
            hierarchy.push_back(members.front()->get_name());                   // особенности вывода - перед очередным уровнем подчиненных
                                                                                // экземпл€ров выводим им€ корневого дл€ них объекта
            for (auto p : slaves) {
                members.push(p);
                hierarchy.push_back((p)->get_name());
            }
        }
        members.pop();                                                          // удал€ем первый элемент в очереди, указыва€ на то, что данный уровень иерархии пройден
    }
    return hierarchy;
}

bool cl_application::IsUniqueElem(std::vector<std::string> vec, unsigned int count)
{
    // прин€та условность, что если метод get_name()
    // возвращает идентичные строки дл€ разных указателей,
    // то они указывают на один и тот же объект
    // (не могут встречатс€ два разных объекта с одинаковым именем)

    for (std::vector<std::string>::iterator p = vec.begin(), t = vec.begin() + count; p != t; p++)
    {

        if (*p == *t)
        {
            //std::cout << "element " << *p << "is ununique" << std::endl;
            return false;
        }
    }
    return true;
}

std::vector <bool>cl_application::get_mask(std::vector<std::string> hierarchy) {
    std::vector<bool>mask;
    int count = 0;
    // при помощи функции transform заполн€ем в вектор mask_
    // где count - пор€дковый номер элемента в векторе
    transform(hierarchy.begin(), hierarchy.end(), back_inserter(mask), [&count, hierarchy](std::string current)->bool {
        return cl_application::IsUniqueElem(hierarchy, count++);
        });
    return mask;
}

size_t cl_application::sum_element(std::vector<bool>mask) {
    return std::count_if(mask.begin(), mask.end(), [](bool x)->int {return !x; });
}

std::vector<std::vector< std::string>> cl_application::get_2_dim_hierarchy()//IBase* root)
{
    cl_application* root = this;
    std::vector<std::string> hierarchy = cl_application::get_horizontal_ordered_hierarchy(root);
    std::vector<std::vector<std::string>> matrix;
    std::vector<bool>mask_ = get_mask(hierarchy);
    size_t row = sum_element(mask_);
    size_t g = 0;
    auto lambda = [](std::vector<bool>mask_, std::vector< std::string> line, size_t& g)->std::vector<std::string> {
        std::vector<std::string>cur_line;
        bool first = true;
        for (int i = g; i < line.size(); i++) {
            if ((!(mask_[i]) && !first) || line[i] == line.back()) {
                if (g != line.size()) {
                    if (line[i] == line.back())
                        i++;
                    for (; g != i; g++)
                        cur_line.push_back(line[g]);
                }
                return cur_line;
            }
            first = false;
        }
    };
    if (!mask_.empty())
        for (auto i = 0; i <= row; i++)
            matrix.push_back(lambda(mask_, hierarchy, g));
    return matrix;
}

void cl_application::show_2_dim_hierarchy()
{
    std::vector<std::vector< std::string>> matrix = get_2_dim_hierarchy();
    std::for_each(matrix.begin(), matrix.end(), [matrix](std::vector<std::string> str)->void {
        for (auto a : str) {
            std::cout << a;
            if (a != str.back())
                std::cout << "  ";
        }
        if (str != matrix.back())std::cout << std::endl;
        });
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