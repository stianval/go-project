#include <GL/glut.h>

#define LWIDTH 0.008

int xfields, yfields;
double dx, dy;

void draw_board() {
	int i, j;
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
}

void game_init ()
{
	xfields = yfields = 19;
	dx = 1.8/xfields;
	dy = 1.8/yfields;
}

void game_display() {
	glClear(GL_COLOR_BUFFER_BIT);
	draw_board();
    glutSwapBuffers();
}

void game_keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(EXIT_SUCCESS);
		default:
			break;
	}
}

void game_idle() {
}

void game_mouse(int x, int y) {
}
