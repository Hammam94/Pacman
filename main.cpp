#include <iostream>
#include <string>
#include <vector>
#include "glut.h"
#include "object_type.h"
#include "grid.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Pacman - Hassan & Hammam & Magdy"

#define PI 3.1415926535897932384626433832795

using namespace std;

static float characterRadius = 0.1;
static float wallSide = 0.25;
static float foodRadius = 0.05;
static float enemyRadius = 0.1;
static double timer = 0.0;
int step = 1;
grid g("maze.txt");
//float charMoveX = 0;
//float charMoveY = 0;
int charPosX;
int charPosY;

int dx[] = {0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0 };

vector<int> enemyPosX;
vector<int> enemyPosY;

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
	for (double i = 0; i < 2 * PI; i += PI / 50) {
		glVertex3f(x + (cos(i) * enemyRadius), y + (sin(i) * enemyRadius), 0.0);
	}
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
	dim = dim - 1;
	if (c == dim / 2) return 0;
	float diff = 2.0 / (dim / 2);
	int t = c < (dim / 2) ? c : (dim / 2) - (c - (dim / 2));
	GLfloat place = 2.0 - (t * diff);
	place = c < (dim / 2) ? -1 * place : place;
	return place;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();

	int index = 0;
	for (int i = 0; i < g.get_height(); ++i) {
		for (int j = 0; j < g.get_width(); ++j) {
			object obj = g.get_object(i, j);
			switch (obj.get_object_type())
			{
			case EMPTY_OBJECT:
				break;
			case WALL:
				drawWall(getCoordinate(j, g.get_height()), -1 * getCoordinate(i, g.get_width()));
				break;
			case COIN:
				drawFood(getCoordinate(j, g.get_height()), -1 * getCoordinate(i, g.get_width()));
				break;
			case PLAYER:
				drawCharacter(getCoordinate(charPosY, g.get_height()), -1 * getCoordinate(charPosX, g.get_width()));
				break;
			case ENEMY:
				drawEnemy(getCoordinate(enemyPosY[index], g.get_height()), -1 * getCoordinate(enemyPosX[index], g.get_width()));
				index++;
				index %= 3;
				break;
			default:
				break;
			};
		}
	}

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'w':
		charPosX -= step;
		glutPostRedisplay();
		break;
	case 's':
		charPosX += step;
		glutPostRedisplay();
		break;
	case 'a':
		charPosY -= step;
		glutPostRedisplay();
		break;
	case 'd':
		charPosY += step;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
	default:
		break;
	}
}

void idle() {
	timer += 0.00000025;
	if (timer > 1.0) {
		for (int i = 0; i < enemyPosX.size(); i++) {
			int r = (rand() * 15) % 4;
			if (enemyPosX[i] + dx[r] < 0 || enemyPosX[i] + dx[r] >= g.get_width()) {
				continue;
			}
			if (enemyPosY[i] + dy[r] < 0 || enemyPosY[i] + dy[r] >= g.get_height()) {
				continue;
			}
			object obj = g.get_object(enemyPosX[i] + dx[r], enemyPosY[i] + dy[r]);
			if (obj.get_object_type() != WALL) {
				enemyPosX[i] += dx[r];
				enemyPosY[i] += dy[r];
				enemyPosX[i] %= g.get_width();
				enemyPosY[i] %= g.get_height();
			}
		}
		timer = 0;
		display();
	}
}

int main(int argc, char* argv[]) {
	int n = g.get_height();
	int m = g.get_width();
	cout << g.get_width() << endl;
	cout << g.get_height() << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			object tmp = g.get_object(i, j);
			cout << tmp.get_object_type();
			if (tmp.get_object_type() == ENEMY) {
				enemyPosX.push_back(i);
				enemyPosY.push_back(j);
			}
			if (tmp.get_object_type() == PLAYER) {
				charPosX = i;
				charPosY = j;
			}
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
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

