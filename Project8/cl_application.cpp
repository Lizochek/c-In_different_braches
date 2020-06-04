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
using namespace std;

cl_application::cl_application() : cl_base::cl_base() {}


void cl_application::bild_tree_objects()
{
	/*
set_connect ( SIGNAL_D ( signal_to_ob_3 ),   p_ob_3,
			  HENDLER_D ( p_ob_3 -> hendler_1 ) );
			  emit_signal ( SIGNAL_D ( signal_to_ob_3 ), s_command );

			  */

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			char ch;
			cin >> ch;    
			mas[i][j] = new cl_base();
			(*mas[i][j]).set_value((ch=='1'?"1":"0"));
		}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i > 0)
			{
				mas[i][j]->add_child(mas[i - 1][j]);
			}
			if (j < 9) {
				mas[i][j]->add_child(mas[i][j + 1]);

			}
			if (i < 9)
			{
				mas[i][j]->add_child(mas[i + 1][j]);
			}

		}
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
	for (int i = 0; i < 10; i++)
	{
		if (mas[i][0]->get_value()== "1") {
			string filler = "0";
			hendler_2(mas[i][0], filler);
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << (mas[i][j]->get_value());
		}
		cout << endl;
	}
    
    for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) 
			delete mas[i][j];
        
	return 0;
}
int const  cl_application::get_class() { return 1; }

void cl_application::signal(std::string& s)  
{
    s+="class1"+this->get_name();
}
    
void cl_application::handler(cl_base* p_ob, std::string& s)  
{
    std::cout<<"class1 handler s: "<<s<<std::endl;
}

void hendler_1(cl_base* p_ob, std::string& s) {
    int c=0;
	for (cl_base* child : p_ob->get_children())
		if ( child->get_value()== "1")
        {
            p_ob->set_connect(SIGNAL_D(cl_application::signal_1), child, HENDLER_D(hendler_2));
            c++;
        }
     if(c) p_ob->emit_signal(SIGNAL_D(cl_application::signal_1), p_ob->get_value());
     else p_ob->emit_signal(SIGNAL_D(cl_application::signal_2), p_ob->get_value());
}
void hendler_2(cl_base* p_ob, std::string& s) {
	hendler_1(p_ob, s);
	p_ob->set_value("F");
}