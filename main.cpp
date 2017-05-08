#include <windows.h>
#include <glut.h>
#include "Grid.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "PacMan - Hassan : Hammam"

using namespace std;

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	Grid grid;
	glutDisplayFunc(&(grid.display_callback));
	glutReshapeFunc(&(grid.reshape_callback));
	glutMainLoop();
	return 0;
}

