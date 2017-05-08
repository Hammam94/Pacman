#ifndef STATIONARY_OBJECT_H_INCLUDED
#define STATIONARY_OBJECT_H_INCLUDED

#include "object.h"
#include "stationary_object_type_enum.h"

class stationary_object : object {
public:
	stationary_object(int, int, stationary_object_type_enum);
	stationary_object_type_enum get_stationary_object_type();
private:
	stationary_object_type_enum stationary_object_type;
};

#endif
