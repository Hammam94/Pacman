#include <iostream>
#include <string>
#include "glut.h"
#include "object_type.h"
#include "grid.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Pacman - Hassan & Hammam & Magdy"

#define PI 3.1415926535897932384626433832795

using namespace std;

static float characterRadius = 0.1;
static float wallSide = 0.2;
static float foodRadius = 0.05;
static float enemyRadius = 0.1;
grid g("maze.txt");

void drawCharacter(GLfloat x, GLfloat y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	for (double i = 0; i < 2 * PI; i += PI / 50)
		glVertex3f(x + (cos(i) * characterRadius), y + (sin(i) * characterRadius), 0.0);
	glEnd();
}

void drawWall(GLfloat x, GLfloat y) {
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.5);
	glVertex3f(x - wallSide / 2, y - wallSide / 2, 0.0);
	glVertex3f(x - wallSide / 2, y + wallSide / 2, 0.0);
	glVertex3f(x + wallSide / 2, y + wallSide / 2, 0.0);
	glVertex3f(x + wallSide / 2, y - wallSide / 2, 0.0);
	glEnd();
}

void drawFood(GLfloat x, GLfloat y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	for (double i = 0; i < 2 * PI; i += PI / 50)
		glVertex3f(x + (cos(i) * foodRadius), y + (sin(i) * foodRadius), 0.0);
	glEnd();
}

void drawEnemy(GLfloat x, GLfloat y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (double i = 0; i < 2 * PI; i += PI / 50)
		glVertex3f(x + (cos(i) * enemyRadius), y + (sin(i) * enemyRadius), 0.0);
	glEnd();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)WINDOW_WIDTH, (GLsizei)WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

GLfloat getCoordinate(int c, int dim) {
	if (c == dim / 2) return 0;
	float diff = 2.0 / (dim / 2);
	c = c < (dim / 2) ? c : c - (dim / 2);
	GLfloat place = 2.0 - (c * diff);
	place = c < (dim / 2) ? -1 * place : place;
	return place;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();

	for (int i = 0; i < g.get_height(); ++i) {
		for (int j = 0; j < g.get_width(); ++j) {
			object obj = g.get_object(i, j);
			switch (obj.get_object_type())
			{
			case EMPTY_OBJECT:
				break;
			case WALL:
				drawWall(getCoordinate(j, g.get_width()), getCoordinate(i, g.get_height()));
				break;
			case COIN:
				break;
			case PLAYER:
				break;
			case ENEMY:
				break;
			default:
				break;
			};
		}
	}

	drawCharacter(0.0, 0.0);
	drawWall(2.0, 2.0);
	drawWall(-2.0, 2.0);
	drawWall(-2.0, -2.0);
	drawWall(2.0, -2.0);
	drawFood(0.6, 0.5);
	drawEnemy(0.5, 0.5);

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}


int main(int argc, char* argv[]) {
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
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, g.get_width(), 0, g.get_height());
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

