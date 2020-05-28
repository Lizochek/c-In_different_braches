//см. п. 8.6. методички
#include "cl_application.h"
int main()
{
	cl_application ob_application; 
	//объявление объекта приложение
	ob_application.bild_tree_objects();
	//создание исходного дерева объектов
	return ob_application.exec_app(); 
	//запуск функционирования системы
}