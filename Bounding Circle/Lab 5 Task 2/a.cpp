#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>

#include "RGBA.h"


float theta = 0;
float min_x=100;
float max_x=-100;
float min_y=100;
float max_y=-100;
void setminmax(float xx,float yy)
{if(xx<min_x)
min_x=xx;
if(xx>max_x)
	max_x=xx;
if(yy<min_y)
	min_y=yy;
if(yy>max_y)
	max_y=yy;


}
void myInit(void)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
  //or glAlphaFunc(GL_NOTEQUAL,0.0);// accept fragment if fragment alpha not= reference alpha i.e. 1.0
  
  glViewport(0, 0, 100, 100);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}
void display(void)
{
	glClearColor(1.0f,1.0f,1.0f,0.0f); 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(-50,50,-50,50);
	 glColor3f(0.4f,0.4f,0.6f);
	 glBegin(GL_LINES);
	 for(float i=0; i<2*3.142; i+=0.02){
		 float x = 20*cos(7*i)*cos(i);
		 float y = 20*cos(7*i)*sin(i);
		 

		glVertex2f(x,y);
		 setminmax(x,y);

	 }
	 glEnd();
	 
	 glBegin(GL_LINE_STRIP);
	  glVertex2f(min_x,min_y);
	  glVertex2f(max_x,min_y);
	   glVertex2f(max_x,max_y);
	   glVertex2f(min_x,max_y);
	    glVertex2f(min_x,min_y);
	   glEnd();

	/* glColor3f(0.3f,0.9f,0.9f);
	 glBegin(GL_LINES);
	 glVertex2f(min_x,min_y);
	 glVertex2f(max_x,min_y);
	 glEnd();
	 glBegin(GL_LINES);
	 glVertex2f(max_x,min_y);
     glVertex2f(max_x,max_y);
	 glEnd();
	 glBegin(GL_LINES);
	 glVertex2f(max_x,max_y);
    glVertex2f(min_x,max_y);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(min_x,max_y);
	glVertex2f(min_x,min_y);


    glEnd();*/
	   float mid_x;
	   float mid_y;
	   mid_x=(min_x+max_x)/2;
	   mid_y=(min_y+max_y)/2;
	   float r=sqrt(pow(max_y-mid_y,2)+pow(max_x-mid_x,2));
	   

	   glBegin(GL_LINES);
	   for(float i=0;i<2*3.142;i+=0.02)
	   {
		   glVertex2f(max_x*cos(i),max_x*sin(i));
	   }
	   glEnd();
	   
	   

	  glFlush();
}
//void myTimer(int t){
//	theta =theta +0.02;
//	std :: cout <<y1 <<std :: endl;
//	glutPostRedisplay();
//   glutTimerFunc(100,myTimer,t);
//
//
//}
void myKeyboard(unsigned char key, int x, int y){
	
	glutPostRedisplay();
}

void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Texturing");
  myInit();
  
    glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
  glutMainLoop();
}