#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "object_type.h"

class object {

public:
	object(int, int, object_type);

	int get_x();
	int get_y();
	object_type	get_object_type();

	void set_x(int);
	void set_y(int);
	void set_object_type(object_type);

private:
	int position_x;
	int position_y;
	object_type type;
};
#endif
