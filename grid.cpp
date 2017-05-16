#include <iostream>
#include <string>
#include <fstream>

#include <stdio.h>

#include "grid.h"
#include "object_type.h"
#include "object.h"

using namespace std;

grid::grid(const char* file_path) {
	if (!map_initiated) {
		init_map();
		map_initiated = true;
	}
	ifstream input_stream(file_path);
	string line;
	for (int i = 0; getline(input_stream, line); ++i) {
		this->matrix.push_back(vector<object>());
		for (int j = 0; j < (int)line.size(); ++j) {
			this->matrix[i].push_back(object(i, j, which_object[line[j] - '0']));
		}
	}
}

void grid::init_map() {
	which_object[0] = EMPTY_OBJECT;
	which_object[1] = WALL;
	which_object[2] = COIN;
	which_object[3] = PLAYER;
	which_object[4] = ENEMY;
}

int grid::get_width() {
	return matrix[0].size();
}

int grid::get_height() {
	return matrix.size();
}

object grid::get_object(int i, int j) {
	return matrix[i][j];
}
