#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "object.h"
#include "character_type_enum.h"

class character:object {

public:
	character(int, int, character_type_enum);
	character_type_enum get_character_type();

private:
	character_type_enum character_type;
};
#endif
