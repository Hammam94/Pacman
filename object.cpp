#include "object.h"

object::object(int position_x, int position_y, object_type type) {
	this->position_x = position_x;
	this->position_y = position_y;
	this->type = type;
}


int object::get_x() {
	return position_x;
}


int object::get_y() {
	return position_y;
}

object_type	object::get_object_type() {
	return type;
}

void object::set_x(int position_X) {
	this->position_x = position_x;
}


void object::set_y(int position_y) {
	this->position_y = position_y;
}

void object::set_object_type(object_type type) {
	this->type = type;
}
