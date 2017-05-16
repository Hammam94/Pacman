#include <iostream>
#include <string>

#include "glut.h"
#include "grid.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Pacman - Hassan & Hammam & Magdy"


#define PI 3.1415926535897932384626433832795

using namespace std;

static float sunRadius = 0.1;

void drawSun() {
	GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat color[] = { 255, 223, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glNormal3f(1, 1, 1);

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.5);
	for (double i = 0; i < 2 * PI; i += PI / 50)
		glVertex3f((cos(i) * sunRadius), sin(i) * sunRadius, 0.0);
	glEnd();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)WINDOW_WIDTH, (GLsizei)WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//draw Sun
	glPushMatrix();
	drawSun();
	/*
	drawSun();
	drawSun();
	drawSun();
	*/
	glPopMatrix();

	glFlush();
	//glutSwapBuffers();
}


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
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutCreateWindow("OpenGL - Draw Circle");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

