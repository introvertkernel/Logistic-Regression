void Write(double x,double y,double z,double scale,char *s);
void redisplay(void);
void myreshape2 (int w, int h);
void initOpenGL();
void keyboard(unsigned char key,int x,int y);
void func1(void);

void motion(void);
void myinit();
void myreshape2 (int w, int h);
#include <math.h>        // For math routines (such as sqrt & trig). 
#include <stdio.h> 
#include <GL/glut.h> 
#include<string.h>

#include "Output.h"
#include "Output.cpp"

static int flag=1,l,m,w,aspectRatio;



void *fonts[]=
{
    GLUT_BITMAP_9_BY_15,
    GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24,
};



void print(int x, int y, char *string,void *font)
{
    int len, i;
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
  
}

void page1()
{

    glColor3f(0.7,1.0,0.0);
    print(320,580,"ATRIA INSTITUTE OF TECHNOLOGY",fonts[2]);
    glColor3f(1.0,0.5,0.0);    
    print(300,530,"COMPUTER GRAPHICS MINI PROJECT ON",fonts[2]);
    // glColor3f(0.0,0.0,0.8);
    // print(390,480,"   Logistic Regresion Simulation",fonts[0]);
    glColor3f(0.4,0.0,1.0);
    print(305,450,"Logistic Regresion Simulation Using OpenGL",fonts[2]);
    glColor3f(0.0,0.0,0.0);    
    print(440,370,"SUBMITTED BY",fonts[0]);
   
    glColor3f(0.1,0.1,0.7);
    print(380,335,"Gurunatha Srinivasa Bhatta",fonts[2]);
    glColor3f(0.1,0.8,0);
    print(425,315,"(1AT15CS026)",fonts[2]);

    glColor3f(0.8,0.1,0.2);
    print(420,200,"Under the guidance of: ",fonts[0]);
    glColor3f(1.0,0.2,0.7);
    print(435,160,"Mr. Sathisha G",fonts[2]);
    glColor3f(0.3,0.1,0.0);
    print(420,130,"Lecturer,Dept of CS&E",fonts[0]);
    print(405,110,"Atria Institute of Technology",fonts[0]);
    
    print(415,85," Press 'c' to continue",fonts[0]);
}

void page2()
{
    glColor3f(0.0,1.0,0.0);
    print(380,600,"~~~~~~",fonts[2]);
   
    glColor3f(0.8,0.1,0.2);
    print(380, 580, "MENU",fonts[2]);
   
    glColor3f(0.0,1.0,0.0);
    print(380,560,"~~~~~~",fonts[2]);
    glColor3f(0.6,0.3,0.7);
   
    print(100,400,"1 -> Logistic Regresion",fonts[2]);
    print(100,350,"2 -> Simulation",fonts[2]);
   // print(100,300,"3 -> Start",fonts[2]);
    print(100,300,"3 -> Quit",fonts[2]);
    print(400,150," Press 'b' to go back",fonts[2]);
}

void page3()
{
    glColor3f(0.8,0.1,0.2);
    print(450, 580, "Information",fonts[2]);

    glColor3f(0.6,0.3,0.7);
    print(100,500,"Logistic regression is a technique borrowed by machine learning from the field of statistics.",fonts[2]);
    print(100,475,"It is the go-to method for binary classification problems (problems with two class values).",fonts[2]);
    print(100,425,"Logistic regression is like linear regression in that the goal is to find the values for the coefficients that",fonts[2]);
    print(100,400,"weight each input variable.",fonts[2]);
    print(100,375,"Unlike linear regression, the prediction for the output is transformed using a non-linear function called the",fonts[2]);
    print(100,350,"logistic function.",fonts[2]);
    print(100,300,"The logistic function looks like a big S and will transform any value into the range 0 to 1.",fonts[2]);
    print(100,275,"This is useful because we can apply a rule to the output of the logistic function to snap values to 0 and 1 (e.g. IF",fonts[2]);
    print(100,250,"less than 0.5 then output 1) and predict a class value.",fonts[2]);
    print(400,100," Press 'b' to go back",fonts[2]);
}

void page4()
{
    int k;

    float x,y,u,blend;

	glClear(GL_COLOR_BUFFER_BIT);

	// To draw points
	glColor3f(0.0,1.0,0.0);
	glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2f(80, 34);
	    glVertex2f(85, 24);
		glVertex2f(78, 24);
		glVertex2f(46, 35);
		glVertex2f(67, 47);
		glVertex2f(85, 26);
		glVertex2f(78, 68);
		glVertex2f(86, 56);
		glVertex2f(82, 54);
		glVertex2f(56, 69);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex2f(34, 38);
		glVertex2f(46, 35);
		glVertex2f(56, 69);
		glVertex2f(43, 47);

	glEnd();
		// Simple try
		// for(int g=10,h=80;g<80,h<150;g++,h++)
		// {	g=g-2;
		// 	h=h+3;
		// 	glVertex2f(80, g);
		// 	h=h-2;
		// 	g=g+3;
		// }


	glColor3f(0.0,0.0,1.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.001)
	{x=0;y=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=bzco[k][0]*blend;
			y+=bzco[k][1]*blend;
		}
		glVertex2f(x,y);

	}
	glEnd();

	//moving points
	
	// glBegin(GL_POINTS);
	// glVertex2f(bzco[1][0],bzco[1][1]);
	// glVertex2f(bzco[2][0],bzco[2][1]);
	// glEnd();
	

	glFlush();
	glutSwapBuffers();
}



// void Reshape1(int w, int h) /*new reshape function for pages*/
// {
//     float aspectRatio;
//     l=w,m=h;
//     glViewport( 0, 0, w, h );   
//     aspectRatio = (float)w/(float)h;
//     glMatrixMode( GL_PROJECTION );
//     glLoadIdentity();
//     gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );
//     glMatrixMode( GL_MODELVIEW );
// }

void myreshape2 (int w, int h) 
{ 
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);  
   glMatrixMode (GL_PROJECTION); 
   glLoadIdentity (); 
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
   glTranslatef (0.0, 0.0, -5.0); 
}

void key(unsigned char key, int x, int y)
{
  if(flag==1)
    {
        if(key=='c')
        {
            flag=2;
            glutPostRedisplay();
        }
    }
    else if(flag==2)
    {
        switch(key)
        {
        case '1': flag=3;
                glutPostRedisplay();
                break;
        case '2': flag=4;
                glutPostRedisplay();
                break;
        case '3': exit(0);
                break;
        // case '3': exit(0);
        case 'b': flag=1;
                 glutPostRedisplay();
                 break;
        }
    }
    else if(flag==3)
    {
        if(key=='b')
        {
            flag=2;
            glutPostRedisplay();
        }
    }
    else if(flag==4)
    {
        if(key=='b')
        {
            flag=2;
            glutPostRedisplay();
        }
    }
    
}
void init(void)
{
    glutIdleFunc(motion);
    // if(flag == 4){
    //     glClearColor(1.0,1.0,1.0,1.0);
    //     glColor3f(1.0,0.0,0.0);
    //     glPointSize(5.0);
    //     gluOrtho2D(0.0,320.0,0.0,300.0);
    // }
    static GLfloat lightpos[] = {.5, .75, 1.5, 1};

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glEnable(GL_CULL_FACE);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

}

void click(int id)
{
    switch(id)
    {
    case 0: return;
    break;
    case 1: return;
   
    break;
    case 2: exit(0);
    }
}

void display()
{
    glClearColor(1.0,1.0,1.0,1.0);
    // glutFullScreen();
   
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1000, 0.0, 650,-2000,1500);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(5);
   
    if(flag==1)
    {
        page1();
    }
    else if(flag==2)
    {
        page2();
    }
    else if(flag==3)
    {
        page3();
  		// glPointSize(5.0);
   		// gluOrtho2D(0.0,350.0,0.0,550.0);
    }
    else if(flag==4)
    {
        function();
  		// glPointSize(5.0);
   		// gluOrtho2D(0.0,350.0,0.0,550.0);
    }
    glFlush();
    glutSwapBuffers();
}


#define MIN_COLOR_BITS 4
#define MIN_DEPTH_BITS 8
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(0, 0);
    if (argc > 1) {
        glutInitDisplayString("samples stencil>=3 rgb depth");
    }
    else {
        glutInitDisplayString("samples stencil>=3 rgb double depth");
    }
    glutCreateWindow("Logistic Function");
    glutFullScreen();
    glutReshapeFunc(myreshape2);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}