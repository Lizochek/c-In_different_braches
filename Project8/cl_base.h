#ifndef CL_BASE_H //��. 5.7 ���������
#define CL_BASE_H
#include <vector>
#include <map>
#include <string>
#include <list>
class cl_base//��. �.8.3
{
protected:
	/*props*/
	  /*������������ �������;*/
	std::string name;
	/*��������� �� �������� ������ �� ������ �������� ��������;*/
	cl_base* head;
	/*�������� ���������� �� ������������ ����������� �������� (��������-��������).*/
	std::list<cl_base*> children;
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
	std::string const get_name();
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
	virtual  int const get_class();
	//������ ��������
	std::list< cl_base* >  get_children();
	/*���������� ������ ������� �������*/
	void add_child(cl_base* obj);
	/*��������� ��������� �� ������ ������� �� ����� �������*/
	cl_base* const get_child(std::string);
	/*��������� ���������� ����������� ��������*/
	size_t const child_count();
	/*��������� ��������� �� ������ ������� �� ������� � ������ ����������� ��������*/
	cl_base* const get_child(size_t);
	/*�������� ������� ������� (������� ��� ����������� ������� �� ��������)*/
	void delete_child(cl_base*);
	//-----------------
	  /*��������� ��������� �� ������ �� ���������� �� ������ ��������*/
	cl_base* get_from_tree(std::string);

	/*��������� ����� ����� �������� � ������������*/
	void set_connect(void (*s_ignal) (std::string&),
		cl_base* p_ob_hendler,
		void (*h_endler) (cl_base* p_pb, std::string&));
	/*�������� ����� ����� �������� � ������������*/
	void delete_connect(void (*s_ignal) (std::string&),
		cl_base* p_ob_hendler,
		void (*h_endler) (cl_base* p_pb, std::string&));
	/*������ ������� � �������� ���������� ���������*/
	/*����� �������� �������� �� ���������� �������� � ������������. ��� ������ ������� (������ ������ emit_signal) � �������� ���������� ���������� ��������� �� ����� ������� � ��������� ��������� ���������� ������������ ���������. �� �������������� ��������� ����� ������� ���������� ���� ��� � �� ������ ���� ��� �����������, ��������� � ������ ��������. ��������� ���������� ������ ������� ���������� �� ������ � ��� ���������� ����� ���� ��������������� ���������� ���������� ������ �������. ��-�� ��������� ���������� ������������ ���������� �� ��������. ��� �������������� �������� ����������� ��������� ���� ������������ ��� ������ �������.*/

	void emit_signal(void (*s_ignal) (std::string&), std::string& s_command);
	
private:
	struct o_sh {
		cl_base* p_cl_base;
		void   (*p_hendler) (cl_base* p_ob, std::string&);
	};

	std::multimap < void (*) (std::string&), o_sh* > connects;
	std::multimap < void (*) (std::string&), o_sh* > ::iterator  it_connects;
	char value;
public:
	void signal_1(std::string&);
	void signal_2(std::string&);
	
	char get_value();
	void set_value(char);
	
	

};



#endif