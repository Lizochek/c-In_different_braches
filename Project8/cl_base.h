#ifndef CL_BASE_H //см. 5.7 методичку
#define CL_BASE_H
#include <vector>
#include <map>
#include <string>
#include <list>
class cl_base//см. п.8.3
{
protected:
	/*props*/
	  /*наименование объекта;*/
	std::string name;
	/*указатель на головной объект на дереве иерархии объектов;*/
	cl_base* head;
	/*перечень указателей на иерархически подчиненных объектов (объектов-потомков).*/
	std::list<cl_base*> children;
	/*состояние объекта*/
	int state = 0;
	/*methods*/
public:
	/*конструктор объекта с параметром - указатель на головной объект*/
	cl_base(cl_base*);
	//конструктор по умолчанию
	cl_base();
	/*конструктор объекта с параметрами - имя объекта, указатель на головной объект*/
	cl_base(std::string, cl_base*);
	/*конструктор объекта с параметрами - имя объекта, указатель на головной объект ,состояние*/
	cl_base(std::string, cl_base*, int);
	/*получения имени объекта*/
	std::string const get_name();
	/*присвоения имени объекту*/
	void set_name(std::string);

	/*получения указателя на головной объект*/
	cl_base* const get_head();
	/*переопределения головного объекта*/
	void set_head(cl_base*);

	/*получения номера состояния объекта*/
	int const get_state();
	/*определения номера состояния объекта*/
	void set_state(int);

	/*класс принадлежности*/
	virtual  int const get_class();
	//список потомков
	std::list< cl_base* >  get_children();
	/*добавление нового объекта потомка*/
	void add_child(cl_base* obj);
	/*получения указателя на объект потомок по имени объекта*/
	cl_base* const get_child(std::string);
	/*получения количества подчиненных объектов*/
	size_t const child_count();
	/*получения указателя на объект потомок по индексу в списке подчиненных объектов*/
	cl_base* const get_child(size_t);
	/*удаления объекта потомка (удалить все подчиненные объекты по иерархии)*/
	void delete_child(cl_base*);
	//-----------------
	  /*получения указателя на объект по координате на дереве объектов*/
	cl_base* get_from_tree(std::string);

	/*установки связи между сигналом и обработчиком*/
	void set_connect(void (*s_ignal) (std::string&),
		cl_base* p_ob_hendler,
		void (*h_endler) (cl_base* p_pb, std::string&));
	/*удаления связи между сигналом и обработчиком*/
	void delete_connect(void (*s_ignal) (std::string&),
		cl_base* p_ob_hendler,
		void (*h_endler) (cl_base* p_pb, std::string&));
	/*выдачи сигнала и передачи текстового сообщения*/
	/*Особо обратить внимание на реализацию сигналов и обработчиков. При выдаче сигнала (вызове метода emit_signal) в качестве аргументов передаются указатель на метод сигнала и строковая переменна содержащая определенное сообщение. По реализованному алгоритму метод сигнала вызывается один раз и по одному разу все обработчики, связанные с данным сигналом. Строковая переменная методу сигнала передается по ссылке и его содержимое может быть отредактировано алгоритмом реализации метода сигнала. Та-же строковая переменная обработчикам передается по значению. Так обеспечивается передача одинакового сообщения всем обработчикам при выдаче сигнала.*/

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