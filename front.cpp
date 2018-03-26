void Write(double x,double y,double z,double scale,char *s);
void redisplay(void);
void myreshape2 (int w, int h);
#include<math.h>        // For math routines (such as sqrt & trig) 
#include<stdio.h> 
#include<GL/glut.h> 
#include<string.h>
void Write(double x,double y,double z,double scale,char *s) 
{ 
   int i,l=strlen(s);
   glPushMatrix();
   glTranslatef(x,y,z);
   glScalef(scale,scale,scale);
   for (i=0;i <l;i++) 
   glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]); 
   glPopMatrix(); 
}

void redisplay(void) 
{ 
     
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0, 0.0, 0.0);
    Write(-4.0,2.5,0.0,0.003,"    ATRIA INSTITUTE OF TECHNOLOGY");
    Write(- 2.5,1.5,0.0,0.002,"    ATRIA INSTITUTE OF TECHNOLOGY");
    Write(-1.5,0.5,0.0,0.002,"    ATRIA INSTITUTE OF TECHNOLOGY"); 

//     Write(- 2.5,1.5,0.0,0.002,"    Graphical Implementation of");
//     glColor3f(0,0,1); 
//     Write(-0.8,1.0,-0.6,0.002," NETWORK SYSTEM ");
//     glColor3f(0.7,0,1); 
//     Write(-1.5,0.5,0.0,0.002,"Press 'C' to continue.......");
//     glColor3f(1,0.5,0); 
//     Write(-2.5,-0.80,0.0,0.0015,"              Submitted By:        ");
//     glColor3f(0,0,1); 
//     Write(-3.0,-1.1,0.0,0.0015,"A.Anitha Jagadeesh                         Namratha.P");
//     glColor3f(0,0,1); 
//     Write(-3.0,-1.3,0.0,0.0015,"(1AT07CS001)                            (1AT07CS032)");
//     glColor3f(0,0,1); 
//     Write(-2.2,-1.7,0.0,0.0015,"          Under The Guidance Of:    ");
//     glColor3f(0,0,1); 
//     Write(-2.2,-1.9,0.0,0.0015,"           Mr. GOUTAM        ");
//     glColor3f(0,0,1); 
//     Write(-2.2,-2.1,0.0,0.0015,"          Lecturer,Dept. of CS&E      ");
//     glColor3f(0,1,1); 
//     Write(-1.6,-2.5,0.0,0.0015,"            ATRIA              ");
 
//     Write(-1.8,-2.7,0.0,0.0015,"           ANANDNAGAR             ");
 
//     Write(-1.8,-2.9,0.0,0.0015,"         Bangalore-560024      ");
 
    glFlush(); 
 
}
    void myreshape2 (int w, int h) 
    { 
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);  
    glMatrixMode (GL_PROJECTION); 
    glLoadIdentity (); 
    gluPerspective( 65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    glTranslatef (0.0, 0.0, -5.0);
    }

    int main( int argc, char** argv ) 
    { 
        glutInit(&argc, argv); 
    
        glutInitWindowSize( 1024, 700 );
    //glutInitWindowPosition( 0, 0 );
    glutCreateWindow("introduction"); 
        glutReshapeFunc(myreshape2); 
        glutDisplayFunc(redisplay); 
        //glutKeyboardFunc(keyboard1); 
            glutMainLoop(  ); 
        return(0);    // This line is never reached. 
    }