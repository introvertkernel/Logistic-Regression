#include<stdio.h>
#include <GL/glut.h>

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// glBegin(GL_QUADS);
	// 	glColor3f(1.0,0.0,0.0);
	// 	glVertex2f(-0.5, 0.1);     // Define vertices in counter-clockwise (CCW) order
	// 	glVertex2f(-0.2, 0.1);     //  so that the normal (front-face) is facing you
	// 	glVertex2f(-0.2, 0.5);
	// 	glVertex2f(-0.5, 0.5);
	// glEnd();

	// glBegin(GL_LINES);
	// 	glColor3f(1.0,0.0,0.0);
	// 	// glVertex3f(-30.0,12.0,3.0);
	// 	// glVertex3f(-22.0,12.0,3.0);
	// 	// glVertex3f(-22.0,12.0,3.0);
	// 	// glVertex3f(-22.0,37.0,3.0);
	// 	// glVertex3f(-22.0,37.0,3.0);
	// 	// glVertex3f(-30.0,37.0,3.0);
	// 	// glVertex3f(-30.0,37.0,3.0);
	// 	// glVertex3f(-30.0,12.0,3.0);

	// 	// glVertex3f(30.0,12.0,3.0);
	// 	// glVertex3f(22.0,12.0,3.0);
	// 	// glVertex3f(22.0,12.0,3.0);
	// 	// glVertex3f(22.0,37.0,3.0);
	// 	// glVertex3f(22.0,37.0,3.0);
	// 	// glVertex3f(30.0,37.0,3.0);
	// 	// glVertex3f(30.0,37.0,3.0);
	// 	// glVertex3f(30.0,12.0,3.0);

    // glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();
	

}

int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(800,800);
	glutInitWindowSize(800,800);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 1;
}