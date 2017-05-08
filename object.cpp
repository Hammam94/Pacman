#include "object.h"

object::object(int position_x, int position_y) {
	this->position_x = position_x;
	this->position_y = position_y;
}


int object::get_x() {
	return position_x;
}


int object::get_y() {
	return position_y;
}


void object::set_x(const int position_X) {
	this->position_x = position_x;
}


void object::set_y(const int position_y) {
	this->position_y = position_y;
}