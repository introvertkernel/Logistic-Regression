#include<GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(10.0,110.0);
	glVertex2f(110.0,80.0);
	glVertex2f(110.0,80.0);
	glVertex2f(200.0,100.0);
	glEnd();
	glFlush();
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	gluOrtho2D(0.0,550.0,0.0,550.0);
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("lines");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}