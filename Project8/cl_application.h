
#ifndef CL_APP
#define CL_APP
//см. 8.5 методичку
#include "cl_base.h"
class cl_application : public cl_base
{
public:
    cl_application();

    void bild_tree_objects();
    int exec_app();

    static size_t sum_element(std::vector< bool >);
    // подсчитывает количество false-элементов в массиве

    static std::vector<bool> get_mask(std::vector<std::string>);
    // метод возвращает вектор по размеру равный hierarchy, где
    // 0 - соотвествующий элемент hierarchy встречалс€ ранее

    std::vector<std::vector < std::string>> get_2_dim_hierarchy();
    // метод строит двумерное представление ирархии объектов

    void show_2_dim_hierarchy();

    static std::vector<std::string> get_horizontal_ordered_hierarchy(cl_application* root);
    // !!!(обход в ширину)!!!
    // метод, возвращающий список указателей
    // на объекты класса Lord, представл€ющий
    // собой развернутую в строку иерархию
    // производных и корневых объектов

    static bool IsUniqueElem(std::vector<std::string> vec, unsigned int pos);
    // 0 - элемент на позиции pos имеет хот€ бы одного подчиненного
    // 1 - элемент на позиции pos не имеет ни одного подчиненного

    int const  get_class() override;

};
#endif