#define SIGNAL_D(  signal_f  ) ( ( void ( * ) ( std::string & ) ) ( & ( signal_f  ) ) )
#define HENDLER_D( hendler_f ) ( ( void ( * ) ( cl_base *, std::string & ) ) ( & ( hendler_f ) ) )
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
#include <vector>
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

void cl_application::set_connects()
{
    cout<<"Set connects"<<endl;
    int connect_num;
    cin>>connect_num;
    while(connect_num)
    {
        string from, to;
        cl_base* ob_emitter, *ob_acceptor;
        void (*signal) (std::string&) ;
        void ( *handler ) ( cl_base *, std::string & ) ;
        cin>>from>>to;
        //ищем объекты
        ob_emitter = this->get_child(from);
        ob_acceptor = this->get_child(to);
        //выбираем сигнал-источник
        if(ob_emitter->get_class()==1)
            signal = SIGNAL_D(cl_application::signal);
        else if (ob_emitter->get_class()==2)
            signal = SIGNAL_D(cl_class2::signal);
        else if (ob_emitter->get_class()==3)
            signal = SIGNAL_D(cl_class3::signal);
        //выбираем обработчик для сигнала
        if(ob_acceptor->get_class()==1)
            handler = HENDLER_D(cl_application::handler);
        else if (ob_acceptor->get_class()==2)
            handler = HENDLER_D(cl_class2::handler);
        else if (ob_acceptor->get_class()==3)
            handler = HENDLER_D(cl_class3::handler);
        //Устанавливаем связь
        ob_emitter->set_connect(signal, ob_acceptor, handler);
        //выводим уведомление об установлении связи
        cout<<connect_num<<" "<<from<<" "<<to<<endl;
        cin>>connect_num;
    }
}
	/*
set_connect ( SIGNAL_D ( signal_to_ob_3 ),   p_ob_3,
			  HENDLER_D ( p_ob_3 -> hendler_1 ) );
			  emit_signal ( SIGNAL_D ( signal_to_ob_3 ), s_command );

			  */

void dfs(cl_base* v, int deep)
{
	for (int i = 0; i < deep; i++) cout << '\t';
	cout << v->get_name() << endl;
	for (cl_base* child : v->get_children())
		dfs(child, deep + 1);
}

int  cl_application::exec_app()
{
    cout << "Object tree"<<endl;
	dfs(this, 0);
    this->set_connects();//установка связей
    cout<<"Emit signals";
    string ob_name;
    cin>>ob_name;
    while(ob_name!="endsignals")
    {
        string s;
        cl_base* ob_emitter = this->get_child(ob_name);
        void (*signal) (std::string&) ; 
        
        cin>>s;   
        
        if(ob_emitter->get_class()==1)
            signal = SIGNAL_D(cl_application::signal);
        else if (ob_emitter->get_class()==2)
            signal = SIGNAL_D(cl_class2::signal);
        else if (ob_emitter->get_class()==3)
            signal = SIGNAL_D(cl_class3::signal);
        
        ob_emitter->emit_signal(signal, s);
        cin>>ob_name;
    }
 
	return 0;
}
int const  cl_application::get_class() { return 1; }

void cl_application::signal(std::string& s)  
{
}
    
void cl_application::handler(cl_base* p_ob, std::string& s)  
{
    std::cout<<std::endl<<"Signal to "<<p_ob->get_name()<<" Text: "<<s;
}