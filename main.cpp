#include <iostream>
#include <string>

#include "grid.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Pacman - Hassan & Hammam & Magdy"

using namespace std;

int main(int argc, char* argv[]) {
	grid g("maze.txt");
	int n = g.get_height();
	int m = g.get_width();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			object tmp = g.get_object(i, j);
			cout << tmp.get_object_type();
		}
		cout << endl;
	}
	cin.get();
	cin.get();
	return 0;
}

