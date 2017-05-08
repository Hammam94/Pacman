#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

class grid {

public:
	grid(string);

private:
	vector<vector<short>> matrix;
};

#endif