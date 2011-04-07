#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "networking.h"

#include "mesh.h"

#define LWIDTH 0.008

int xfields, yfields, rq_sock, sock;
double dx, dy;

GLuint vbo, ebo;

void draw_board() {
	int i;
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

void game_init (int argc, char *argv[])
{

	xfields = yfields = 19;
	dx = 1.8/xfields;
	dy = 1.8/yfields;
	if (argc < 2){
		rq_sock = init_server();
		std::cout << rq_sock;
		//read(socket, buf, 5);
		std::cout << "read!";
	}
	else if (argc == 2){
		sock = init_client(argv[1]);
		//write(socket, buf, 5);
		std::cout << "write!";
	}
	else {
		printf ("Usage: %s [ip]\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	
	load_mesh(&vbo, &ebo, "stone.obj");
}

void game_display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(-1,1,1,-1);
	gluPerspective(60.0, 1, 0.01, 100);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1,1,1, 0,0,0, 0,0,1);
	
	draw_board();
	render_mesh(vbo,ebo);
	//draw_random_mesh();
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
