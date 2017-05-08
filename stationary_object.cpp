#include "stationary_object.h"
#include "stationary_object_type_enum.h"

stationary_object::stationary_object(int position_x, int position_y, stationary_object_type_enum stationary_object) : object(position_x, position_y) {
	this->stationary_object_type = stationary_object_type;
}


stationary_object_type_enum stationary_object::get_stationary_object_type() {
	return stationary_object_type;
}
