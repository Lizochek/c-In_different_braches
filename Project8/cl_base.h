#ifndef CL_BASE_H //��. 5.7 ���������
#define CL_BASE_H
#include<vector>
#include<string>
class cl_base//��. �.8.3
{
protected:
	 /*props*/
	/*������������ �������;*/
	std::string name;
	/*��������� �� �������� ������ �� ������ �������� ��������;*/
	cl_base* head;
	/*�������� ���������� �� ������������ ����������� �������� (��������-��������).*/
	std::vector<cl_base*> children;
	/*��������� �������*/
	int state = 0;
	/*methods*/
public:
	/*����������� ������� � ���������� - ��������� �� �������� ������*/
	cl_base(cl_base*);
	//����������� �� ���������
	cl_base();
	/*����������� ������� � ����������� - ��� �������, ��������� �� �������� ������*/
	cl_base(std::string, cl_base*);
	/*����������� ������� � ����������� - ��� �������, ��������� �� �������� ������ ,���������*/
	cl_base(std::string, cl_base*, int);
	/*��������� ����� �������*/
	std::string  get_name();
	/*���������� ����� �������*/
	void set_name(std::string);


	/*��������� ��������� �� �������� ������*/
	cl_base* const get_head();
	/*��������������� ��������� �������*/
	void set_head(cl_base*);


	/*��������� ������ ��������� �������*/
	int const get_state();
	/*����������� ������ ��������� �������*/
	void set_state(int);


	/*����� ��������������*/
	 int  get_class();
	//������ ��������
	std::vector<cl_base*> get_children();
	/*���������� ������ ������� �������*/
	void add_child(cl_base* obj);
	/*��������� ��������� �� ������ ������� �� ����� �������*/
	cl_base*  get_child(std::string);
	/*��������� ���������� ����������� ��������*/
	size_t const child_count();
	/*��������� ��������� �� ������ ������� �� ������� � ������ ����������� ��������*/
	cl_base*  get_child(size_t);
	/*�������� ������� ������� (������� ��� ����������� ������� �� ��������)*/
	void delete_child(cl_base*);
	//-----------------
/*��������� ��������� �� ������ �� ���������� �� ������ ��������*/
	cl_base* get_from_tree(int);


	/*��������� ����� ����� �������� � ������������*/
	void set_signal(/*???*/);
	/*�������� ����� ����� �������� � ������������*/
	void delete_signal(/*???*/);
	/*������ ������� � �������� ���������� ���������*/
	/*����� �������� �������� �� ���������� �������� � ������������. ��� ������ ������� (������ ������ emit_signal) � �������� ���������� ���������� ��������� �� ����� ������� � ��������� ��������� ���������� ������������ ���������. �� �������������� ��������� ����� ������� ���������� ���� ��� � �� ������ ���� ��� �����������, ��������� � ������ ��������. ��������� ���������� ������ ������� ���������� �� ������ � ��� ���������� ����� ���� ��������������� ���������� ���������� ������ �������. ��-�� ��������� ���������� ������������ ���������� �� ��������. ��� �������������� �������� ����������� ��������� ���� ������������ ��� ������ �������.*/
	void emit_signal(void*, std::string);

};






#endif