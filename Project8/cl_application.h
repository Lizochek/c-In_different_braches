
#ifndef CL_APP
#define CL_APP
//��. 8.5 ���������
#include "cl_base.h"
class cl_application : public cl_base
{
public:
    cl_application();

    void bild_tree_objects();
    int exec_app();

    static size_t sum_element(std::vector< bool >);
    // ������������ ���������� false-��������� � �������

    static std::vector<bool> get_mask(std::vector<std::string>);
    // ����� ���������� ������ �� ������� ������ hierarchy, ���
    // 0 - �������������� ������� hierarchy ���������� �����

    std::vector<std::vector < std::string>> get_2_dim_hierarchy();
    // ����� ������ ��������� ������������� ������� ��������

    void show_2_dim_hierarchy();

    static std::vector<std::string> get_horizontal_ordered_hierarchy(cl_application* root);
    // !!!(����� � ������)!!!
    // �����, ������������ ������ ����������
    // �� ������� ������ Lord, ��������������
    // ����� ����������� � ������ ��������
    // ����������� � �������� ��������

    static bool IsUniqueElem(std::vector<std::string> vec, unsigned int pos);
    // 0 - ������� �� ������� pos ����� ���� �� ������ ������������
    // 1 - ������� �� ������� pos �� ����� �� ������ ������������

    int const  get_class() override;

};
#endif