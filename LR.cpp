// #include <GL/glew.h>    // has to be included before gl.h, or any header that includes gl.h
#include<GL/gl.h>
#include <GL/freeglut.h>
#include<GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}
void initOpenGL(){
    glClearColor(0.8,0.0,0.0,1.0);
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(100.0,100.0);
    glutInitWindowSize(1000,500);
    glutCreateWindow("LR");
    // glutFullScreen();           // making the window full screen
    //Above line works but no controls given
    glutDisplayFunc(display);
    // myinit();
    glutMainLoop();
    return 0;
}