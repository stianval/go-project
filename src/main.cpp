#include <GL/glut.h>

#include "game.h"

void init_gl() {
	glClearColor (1.0, 1.0, 1.0, 1.0); // Set background to white
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SWIDTH,SHEIGHT);
	glutCreateWindow("Go");
	glutDisplayFunc(game_display);
	glutMouseFunc(game_mouse);
	glutKeyboardFunc(game_keyboard);
	glutIdleFunc(game_idle);

	init_gl();
	game_init (argc, argv);

	glutMainLoop();
	return 0;
}
