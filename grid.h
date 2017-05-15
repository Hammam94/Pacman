#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <string>
#include <vector>
#include <map>

#include "object.h"

using namespace std;

class grid {

public:
	grid(const char*);

	int get_width();
	int get_height();

	object get_object(int, int);

private:
	vector<vector<object>> matrix;
	map<int, object_type> which_object;
	bool map_initiated = false;
	void init_map();
};

#endif
