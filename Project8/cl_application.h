#ifndef CL_APP
#define CL_APP
//��. 8.5 ���������
#include "cl_base.h"
class cl_application : public cl_base
{
public:
	cl_application();
	void bild_tree_objects() ;
	int exec_app();
	int const get_class() override;
};
#endif