#include<stdio.h>
#include<GL/glut.h>
void render(void);

int main(char argc,char** argv){
    glutInit(&argc,argv);
    // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |);
    glutInitWindowPosition(-1,-1);
    glutInitWindowSize(700,400);
    glutCreateWindow("Main");

}