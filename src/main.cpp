#if defined(WIN32) || defined(WIN64) || defined(_MSC_VER)
#include <windows.h>
#endif
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define SWIDTH 700
#define SHEIGHT 700
#define LWIDTH 0.008

int xfields, yfields;
double dx, dy;

void display() {
	int i, j;
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.8,0.8,0.5); 
	glVertex3f(-1, -1, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, -1, 0);
	glEnd();
	for (i = 0; i < xfields+1; i++) {
		glBegin(GL_POLYGON);
		glColor3f(0.5,0.0,0.0); 
		glVertex3f(0.9+LWIDTH, -0.9-LWIDTH+i*dy, 0);
		glVertex3f(0.9+LWIDTH, -0.9+LWIDTH+i*dy, 0);
		glVertex3f(-0.9-LWIDTH, -0.9+LWIDTH+i*dy, 0);
		glVertex3f(-0.9-LWIDTH, -0.9-LWIDTH+i*dy, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.5,0.0,0.0); 
		glVertex3f(-0.9-LWIDTH+i*dx, 0.9, 0);
		glVertex3f(-0.9+LWIDTH+i*dx, 0.9, 0);
		glVertex3f(-0.9+LWIDTH+i*dx, -0.9, 0);
		glVertex3f(-0.9-LWIDTH+i*dx, -0.9, 0);
		glEnd();
	}
	glutSwapBuffers();
}

void key(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(EXIT_SUCCESS);
		default:
			break;
	}
}

void idle() {
}

void mouse(int x, int y) {
}

int main(int argc, char **argv) {
	xfields = yfields = 19;
	dx = 1.8/xfields;
	dy = 1.8/yfields;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SWIDTH,SHEIGHT);
	glutCreateWindow("Go");
	glutDisplayFunc(display);
	glutPassiveMotionFunc(mouse);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
