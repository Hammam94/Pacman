#include "character.h"
#include "character_type_enum.h"

character::character(int position_x, int position_y, character_type_enum character_type) : object(position_x, position_y) {
	this->character_type = character_type;
}


character_type_enum character::get_character_type() {
	return character_type;
}

