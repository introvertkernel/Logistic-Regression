/*
 * GL02Primitive.cpp: Vertex, Primitive and Color
 * Draw Simple 2D colored Shapes: quad, triangle and polygon.
 */
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
   
    //# BORDER RECTANGLE BOX 

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    gluOrtho2D( 0, 800, 0, 800);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // important
    glTranslatef( 0.5, 0.5, 0 );

    float offset = 40;
    glColor3ub( 255, 0, 0 );
    
    glBegin(GL_LINE_LOOP);
    glVertex2f( 20,20 );
    glVertex2f( 780,20 );
    glVertex2f( 780, 780 );
    glVertex2f( 20, 780 );
    glEnd();

    int x,y=40;
    while(y<780){
        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(20,y);
        glVertex2f(780,y);
        glEnd();
        y=y+40;

    }
    x=40;
    while(x<780){
        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(x,20);
        glVertex2f(x,780);
        glEnd();
        x=x+40;

    }
   glBegin(GL_POINTS);
   glColor3f(0.0,0.0,1.0);
   glPointSize(50);
   glVertex2d(40,41);
   glEnd();

    // glBegin(GL_LINES);
    //     glColor3f(1.0,0.0,0.0);
    //     glVertex2f(60,40);
    //     glVertex2f(60,460);
    //     glVertex2f(90,40);
    //     glVertex2f(90,460);
    //     glVertex2f(120,40);
    //     glVertex2f(120,460);
    //     glVertex2f(150,40);
    //     glVertex2f(150,460);
    //     glVertex2f(180,40);
    //     glVertex2f(180,460);
    //     glVertex2f(210,40);
    //     glVertex2f(210,460);
    //     glVertex2f(240,40);
    //     glVertex2f(240,460);
    //     glVertex2f(270,40);
    //     glVertex2f(270,460);
    //     glVertex2f(300,40);
    //     glVertex2f(300,460);
    //     glVertex2f(330,40);
    //     glVertex2f(330,460);
    //     glVertex2f(360,40);
    //     glVertex2f(360,460);
    //     glVertex2f(390,40);
    //     glVertex2f(390,460);
    //     glVertex2f(420,40);
    //     glVertex2f(420,460);
    //     glVertex2f(450,40);
    //     glVertex2f(450,460);
    //     glVertex2f(510,40);
    //     glVertex2f(510,460);
    //     glVertex2f(540,40);
    //     glVertex2f(540,460);
    //     glVertex2f(570,40);
    //     glVertex2f(570,460);
    //     glVertex2f(600,40);
    //     glVertex2f(600,460);

    // glEnd();
    // glBegin(GL_LINES);
    //     glColor3f(1.0,0.0,0.0);
    //     glVertex2f(40,60);
    //     glVertex2f(460,60);
    //     glVertex2f(40,90);
    //     glVertex2f(460,90);
    //     glVertex2f(40,120);
    //     glVertex2f(460,120);
    //     glVertex2f(40,150);
    //     glVertex2f(460,150);
    //     glVertex2f(40,180);
    //     glVertex2f(460,180);
    //     glVertex2f(40,210);
    //     glVertex2f(460,210);
    //     glVertex2f(40,240);
    //     glVertex2f(460,240);
    // glEnd();
    // glBegin(GL_POINT);
    //     glColor3f(0.0,0.0,1.0);
    //     glVertex2f(82,92);
    //     glVertex2f(81,91);
    //     glVertex2f(80,90);
    // glEnd();
////#######
// glBegin(GL_LINE);
//             glVertex2f(-30.0,+30.0);
//             glVertex2f(-30.0,80.0);
//         glEnd();
////#######
    

    // glMatrixMode( GL_PROJECTION );
    // glLoadIdentity();
    // double w = glutGet( GLUT_WINDOW_WIDTH );
    // double h = glutGet( GLUT_WINDOW_HEIGHT );
    // glOrtho( 0, w, 0, h, -1, 1);

    // glMatrixMode( GL_MODELVIEW );
    // glLoadIdentity();

    // // important
    // glTranslatef( 0.5, 0.5, 0 );

    // float offset = 40;
    // glColor3ub( 255, 0, 0 );
    
    // glBegin(GL_LINE);
    // glVertex2f( 0+offset, 0+offset );
    // glVertex2f( 0+offset, h-offset );
    // glVertex2f( w-offset, h-offset );
    // glVertex2f( w-offset, 0+offset );
    // glEnd();



    //#DRAW DOTTED LINE 
    
    // glPushAttrib(GL_ENABLE_BIT); 
    // glLineStipple(1, 0xAAAA);
    // glEnable(GL_LINE_STIPPLE);
    // glBegin(GL_LINES);
    // glVertex3f(-.5,.5,-.5);
    // glVertex3f(.5,.5,-.5);
    // glEnd();
    // glPopAttrib();
    /////
   // Define shapes enclosed within a pair of glBegin and glEnd
//    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
//       glColor3f(1.0f, 0.0f, 0.0f); // Red
//       glVertex2f(-0.8f, 0.1f);     // Define vertices in counter-clockwise (CCW) order
//       glVertex2f(-0.2f, 0.1f);     //  so that the normal (front-face) is facing you
//       glVertex2f(-0.2f, 0.7f);
//       glVertex2f(-0.8f, 0.7f);
 
    //   glColor3f(0.0f, 1.0f, 0.0f); // Green
    //   glVertex2f(-0.7f, -0.6f);
    //   glVertex2f(-0.1f, -0.6f);
    //   glVertex2f(-0.1f,  0.0f);
    //   glVertex2f(-0.7f,  0.0f);
 
    //   glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
    //   glVertex2f(-0.9f, -0.7f);
    //   glColor3f(1.0f, 1.0f, 1.0f); // White
    //   glVertex2f(-0.5f, -0.7f);
    //   glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
    //   glVertex2f(-0.5f, -0.3f);
    //   glColor3f(1.0f, 1.0f, 1.0f); // White
    //   glVertex2f(-0.9f, -0.3f);
//    glEnd();
 
//    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
//       glColor3f(0.0f, 0.0f, 1.0f); // Blue
//       glVertex2f(0.1f, -0.6f);
//       glVertex2f(0.7f, -0.6f);
//       glVertex2f(0.4f, -0.1f);
 
//       glColor3f(1.0f, 0.0f, 0.0f); // Red
//       glVertex2f(0.3f, -0.4f);
//       glColor3f(0.0f, 1.0f, 0.0f); // Green
//       glVertex2f(0.9f, -0.4f);
//       glColor3f(0.0f, 0.0f, 1.0f); // Blue
//       glVertex2f(0.6f, -0.9f);
//    glEnd();
 
//    glBegin(GL_POLYGON);            // These vertices form a closed polygon
//       glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//       glVertex2f(0.4f, 0.2f);
//       glVertex2f(0.6f, 0.2f);
//       glVertex2f(0.7f, 0.4f);
//       glVertex2f(0.6f, 0.6f);
//       glVertex2f(0.4f, 0.6f);
//       glVertex2f(0.3f, 0.4f);
//    glEnd();
 
   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
   glutInitWindowSize(800, 800);   // Set the window's initial width & height
   glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}