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

static int flag=1,l,m,w,aspectRatio;
int bzco[4][2]={{0,0},{49,201},{201,99},{320,300}},c[4],n=3;
int s1x,s1y,s2x,s2y;


void *fonts[]=
{
    GLUT_BITMAP_9_BY_15,
    GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24,
};

void bezierCoefficients(int n,int *c)
{
	int k,i;
	for(k=0;k<=n;k++)
	{
		c[k]=1;
        
		for(i=n;i>=k+1;i--)
		    c[k]*=i;
		
            //c[k] = 1 / (1+ exp (i));
		
		for(i=n-k;i>=2;i--)
			c[k]/=i;
		



            /*x <- c(-10:10)
            b = 0 # intercept
            m = 1 # slope
            y <- exp((b + m*x)) / (1 + exp((b + m*x))
            */

           /*
           c[k] = exp((gb + i*gx)) / (1 + exp((gb + i*gx)));
           */
	}
}

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
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.0,50.0);
    glVertex2f(1000.0,50.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.1,0.5);
    glVertex2f(10.0,50.0);
    glVertex2f(30.0,50.0);
    glVertex2f(30.0,100.0);
    glVertex2f(10.0,100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.6,0.5);
    glVertex2f(10.0,100.0);
    glVertex2f(30.0,100.0);
    glVertex2f(30.0,150.0);
    glVertex2f(10.0,150.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.2,0.0);
    glVertex2f(10.0,150.0);
    glVertex2f(30.0,150.0);
    glVertex2f(30.0,200.0);
    glVertex2f(10.0,200.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(10.0,100.0);
    glVertex2f(30.0,100.0);
    glVertex2f(30.0,150.0);
    glVertex2f(10.0,150.0);
    glEnd();
    glFlush();
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

    // glutIdleFunc(motion);
	// myinit();
	// bezierCoefficients(n,c);
	// s1x=-1;s1y=-1;s2x=-1;s2y=1;
    
}

void myinit()
{
    glutIdleFunc(motion);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	gluOrtho2D(0.0,320.0,0.0,300.0);
}

void motion(void)
{
	bzco[1][0]+=s1x;
	bzco[1][1]+=s1y;
	bzco[2][0]+=s2x;
	bzco[2][1]+=s2y;
	if(bzco[1][0]<0||bzco[1][0]>320)
	{
		s1x=-s1x;
	}
	if(bzco[1][1]<0||bzco[1][1]>300)
	{
		s1y=-s1y;
	}
	if(bzco[2][0]<0||bzco[2][0]>320)
	{
		s2x=-s2x;
	}
	if(bzco[2][1]<0||bzco[2][1]>300)
	{
		s2y=-s2y;
	}
	glutPostRedisplay();
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

    //   cone = gluNewQuadric();
    //   qsphere = gluNewQuadric();
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
        page4();
        //motion();
        // glutIdleFunc(motion);
        init();
        bezierCoefficients(n,c);
        s1x=-1;s1y=-1;s2x=-1;s2y=1;
  		// glPointSize(5.0);
   		// gluOrtho2D(0.0,350.0,0.0,550.0);
    }
    
    else if(flag==5)
    {
        glutReshapeFunc(reshape);
        glutKeyboardFunc(key);
        init();
        glutCreateMenu(click);
        // glutAddMenuEntry("Toggle Views",1);
        // glutAddMenuEntry("-------",0);            
        glutAddMenuEntry("Exit",1);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
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
    glutReshapeFunc(myreshape2);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}























//######################################















// #include<assert.h>
// #include<math.h>
// #include<stdio.h>
// #include<stdlib.h>
// #include<GL/glut.h>
// #include<string.h>

// // GLUquadricObj *cone, *base, *qsphere;

// // /* Some <math.h> files do not define M_PI... */
// // #ifndef M_PI
// // #define M_PI 3.14159265358979323846
// // #endif

// // #ifndef __sgi
// // #define trunc(x) ((double)((int)(x)))
// // #endif

// // int draw_passes = 1;
// // int headsUp = 0;

// int bzco[4][2]={{0,0},{49,201},{201,99},{320,300}},c[4],n=3;
// int s1x,s1y,s2x,s2y;

// // typedef struct {
// //   GLfloat verts[4][3];
// //   GLfloat scale[3];
// //   GLfloat trans[3];
// // } Mirror;

// // Mirror mirrors[] = {
// //   /* mirror on the left wall */
// //   {{{-1., -.75, -.75}, {-1., .75, -.75}, {-1., .75, .75}, {-1, -.75, .75}},
// //      {-1, 1, 1}, {2, 0, 0}},

// //   /* mirror on right wall */
// //   {{{1., -.75, .75}, {1., .75, .75}, {1., .75, -.75}, {1., -.75, -.75}},
// //      {-1, 1, 1}, {-2, 0, 0}},
// // };
// // int nMirrors = 2;
// // void *fonts[]=
// // {
// // GLUT_BITMAP_9_BY_15,
// // GLUT_BITMAP_TIMES_ROMAN_10,
// // GLUT_BITMAP_TIMES_ROMAN_24,
// // };
// static int flag=1,l,m,w,aspectRatio;
// //for printing text
// void Write(double x,double y,double z,double scale,char *s) 
// { 
//    int i,l=strlen(s); 
//    glPushMatrix(); 
//    glTranslatef(x,y,z); 
//    glScalef(scale,scale,scale); 
//    for (i=0;i <l;i++) 
//    glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]); 
//    glPopMatrix();
// }
// void reshape(GLsizei w, GLsizei h)
// {
//   glViewport(0, 0, w, h);
  
// }
// void page1()
// {
// glClear(GL_COLOR_BUFFER_BIT); 
//     glColor3f(0.7, 1.0, 0.0);
//     Write(-4.0,2.5,0.0,0.003,"    ATRIA INSTITUTE OF TECHNOLOGY"); 
//     Write(- 2.5,1.5,0.0,0.002,"    Logistic Regression Simulation");
//     // glColor3f(0,0,1); 
//     // Write(-0.8,1.0,-0.6,0.002,"NETWORK SYSTEM");
//     // glColor3f(0.7,0,1); 
//     Write(-1.5,0.5,0.0,0.002,"Press 'C' to continue.......");
//     glColor3f(1,0.5,0); 
//     Write(-2.5,-0.80,0.0,0.0015,"              Submitted By:        ");
//     glColor3f(0,0,1); 
//     Write(-3.0,-1.1,0.0,0.0015,"            Gurunatha Srinivasa Bhatta                ");
//     glColor3f(0,0,1); 
//     Write(-3.0,-1.3,0.0,0.0015,"                 1AT15CS026");
//     glColor3f(0,0,1); 
//     Write(-2.2,-1.7,0.0,0.0015,"         Under The Guidance Of:    ");
//     glColor3f(0,0,1); 
//     Write(-2.2,-1.9,0.0,0.0015,"          Mr. SATHISHA        ");
//     glColor3f(0,0,1); 
//     Write(-2.2,-2.1,0.0,0.0015,"        Lecturer,Dept. of CS&E      ");
//     glColor3f(0,1,1); 
//     Write(-1.6,-2.5,0.0,0.0015,"          ATRIA              ");
 
//     Write(-1.8,-2.7,0.0,0.0015,"         ANANDNAGAR             ");
 
//     Write(-1.8,-2.9,0.0,0.0015,"        Bangalore-560024      ");
 
//     glFlush(); 
 
//     //glFlush(); 
// }

// void page2()
// {
//     printf("hello");
//     // print(400,150," Press 'b' to go back",fonts[2]);
// }

// void page3()
// {
//     int k;

//     float x,y,u,blend;

// 	glClear(GL_COLOR_BUFFER_BIT);

// 	// To draw points
// 	glColor3f(0.0,1.0,0.0);
// 	glPointSize(3);
//     glBegin(GL_POINTS);
//         glVertex2f(80, 34);
// 	    glVertex2f(85, 24);
// 		glVertex2f(78, 24);
// 		glVertex2f(46, 35);
// 		glVertex2f(67, 47);
// 		glVertex2f(85, 26);
// 		glVertex2f(78, 68);
// 		glVertex2f(86, 56);
// 		glVertex2f(82, 54);
// 		glVertex2f(56, 69);
// 	glEnd();

// 	glColor3f(1.0,0.0,0.0);
// 	glPointSize(3);
// 	glBegin(GL_POINTS);
// 		glVertex2f(34, 38);
// 		glVertex2f(46, 35);
// 		glVertex2f(56, 69);
// 		glVertex2f(43, 47);

// 	glEnd();
// 		// Simple try
// 		// for(int g=10,h=80;g<80,h<150;g++,h++)
// 		// {	g=g-2;
// 		// 	h=h+3;
// 		// 	glVertex2f(80, g);
// 		// 	h=h-2;
// 		// 	g=g+3;
// 		// }


// 	glColor3f(0.0,0.0,1.0);
// 	glLineWidth(3.0);
// 	glBegin(GL_LINE_STRIP);

// 	for(u=0;u<1.0;u+=0.001)
// 	{x=0;y=0;
// 		for(k=0;k<4;k++)
// 		{
// 			blend=c[k]*pow(u,k)*pow(1-u,n-k);
// 			x+=bzco[k][0]*blend;
// 			y+=bzco[k][1]*blend;
// 		}
// 		glVertex2f(x,y);

// 	}
// 	glEnd();

// 	//moving points
	
// 	// glBegin(GL_POINTS);
// 	// glVertex2f(bzco[1][0],bzco[1][1]);
// 	// glVertex2f(bzco[2][0],bzco[2][1]);
// 	// glEnd();
	

// 	glFlush();
// 	glutSwapBuffers();
// }

// // void page4()
// // {
   
    
// //     print(200,50,"Press 'b' to go back",fonts[2]);
// // }

// ///////////////////////////////////////////////
// void motion(void)
// {
// 	bzco[1][0]+=s1x;
// 	bzco[1][1]+=s1y;
// 	bzco[2][0]+=s2x;
// 	bzco[2][1]+=s2y;
// 	if(bzco[1][0]<0||bzco[1][0]>320)
// 	{
// 		s1x=-s1x;
// 	}
// 	if(bzco[1][1]<0||bzco[1][1]>300)
// 	{
// 		s1y=-s1y;
// 	}
// 	if(bzco[2][0]<0||bzco[2][0]>320)
// 	{
// 		s2x=-s2x;
// 	}
// 	if(bzco[2][1]<0||bzco[2][1]>300)
// 	{
// 		s2y=-s2y;
// 	}
// 	glutPostRedisplay();
// }

// void bezierCoefficients(int n,int *c)
// {
// 	int k,i;
// 	for(k=0;k<=n;k++)
// 	{
// 		c[k]=1;
        
// 		for(i=n;i>=k+1;i--)
// 		    c[k]*=i;
		
//             //c[k] = 1 / (1+ exp (i));
		
// 		for(i=n-k;i>=2;i--)
// 			c[k]/=i;
		



//             /*x <- c(-10:10)
//             b = 0 # intercept
//             m = 1 # slope
//             y <- exp((b + m*x)) / (1 + exp((b + m*x))
//             */

//            /*
//            c[k] = exp((gb + i*gx)) / (1 + exp((gb + i*gx)));
//            */
// 	}
// }


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
// void key(unsigned char key, int x, int y)
// {
//   if(flag==1)
//     {
//         if(key=='c')
//         {
//             flag=2;
//             glutPostRedisplay();
//         }
//     }
//     else if(flag==2)
//     {
//         switch(key)
//         {
//         case '1': flag=3;
//                 glutPostRedisplay();
//                 break;
//         case '2': flag=4;
//                 glutPostRedisplay();
//                 break;
//         case '3': flag=5;
//                 glutPostRedisplay();
//                 break;
//         case '4': exit(0);
//         case 'b': flag=1;
//                  glutPostRedisplay();
//                  break;
//         }
//     }
//     else if(flag==3)
//     {
//         if(key=='b')
//         {
//             flag=2;
//             glutPostRedisplay();
//         }
//     }
//     else if(flag==4)
//     {
//         if(key=='b')
//         {
//             flag=2;
//             glutPostRedisplay();
//         }
//     }
    
// }
// void init(void)
// {
//     static GLfloat lightpos[] = {.5, .75, 1.5, 1};

//     glEnable(GL_DEPTH_TEST);
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);
//     glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

//     glEnable(GL_CULL_FACE);
//     glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

//     //cone = gluNewQuadric();
//     //qsphere = gluNewQuadric();
//     glClearColor(1.0,1.0,1.0,1.0);
//     glColor3f(1.0,0.0,0.0);
//     glPointSize(5.0);
//     gluOrtho2D(0.0,320.0,0.0,300.0);
  
// }
// void click(int id)
// {
//     switch(id)
//     {
//     case 0: return;
//     break;
//     case 1: return;
   
//     break;
//     case 2: exit(0);
//     }
// }

// void display()
// {
//     glClearColor(1.0,1.0,1.0,1.0);
//    //s glutFullScreen();
   
//     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(0, 1000, 0.0, 650,-2000,1500);
//     glMatrixMode(GL_MODELVIEW);
//     glPointSize(5);
   
//     if(flag==1)
//     {
//         page1();
//     }
//     else if(flag==2)
//     {
//         page2();
//     }
//     else if(flag==3)
//     {
//         page3();
//   		 glPointSize(5.0);
//    		gluOrtho2D(0.0,350.0,0.0,550.0);
       
        
//     }
    
//     else if(flag==5)
//     {
        
        
//        glutReshapeFunc(reshape);
//         glutKeyboardFunc(key);
       
//         init();
//         glutCreateMenu(click);
//         glutAddMenuEntry("Toggle Views",1);
//         glutAddMenuEntry("-------",0);
//         glutAddMenuEntry("Exit",2);
//         glutAttachMenu(GLUT_RIGHT_BUTTON);
//     }
//     glFlush();
//     glutSwapBuffers();
// }



// #define MIN_COLOR_BITS 4
// #define MIN_DEPTH_BITS 8
// int main(int argc, char *argv[])
// {
//     glutInit(&argc, argv);
//     glutInitWindowSize(256, 256);
//     glutInitWindowPosition(0, 0);
//     if (argc > 1) {
//       glutInitDisplayString("samples stencil>=3 rgb depth");
//     } else {
//       glutInitDisplayString("samples stencil>=3 rgb double depth");
//     }
//     glutCreateWindow(argv[0]);
//     glutReshapeFunc(Reshape1);
//     glutDisplayFunc(display);
//     glutIdleFunc(motion);
//     glutKeyboardFunc(key);
//     glutMainLoop();
//     return 0;
// }
