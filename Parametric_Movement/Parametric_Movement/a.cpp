#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <glut.h>
#include <Windows.h>
#include "RGBA.h"

float PIE=3.142;
float xx = 0;
bool check = false;
RGBApixmap pix[6];
void myInit(void)
{
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
  //or glAlphaFunc(GL_NOTEQUAL,0.0);// accept fragment if fragment alpha not= reference alpha i.e. 1.0
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,640,0,480);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 

 
}
void display(void)
{
	
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
   glViewport(0,30,640,480);
  gluOrtho2D(-5,10,-5,10);
  if(check==false){
     glRasterPos2f(xx+1,exp(-xx)*cos(2*PIE*xx));
  }
  else{
	 glRasterPos2f(PIE*cos(xx),PIE*sin(xx));
  }
	 pix[1].mDraw();
	 glFlush();
  
}
void myKeyboard(unsigned char key, int x, int y){
	if(key=='a'){
		check=true;
		xx=0;
	}
	if(key=='s'){
		check=false;
		xx=0;
	}
	glutPostRedisplay();
}


void myTimer(int t)
{
	xx+=0.05;
		std :: cout << xx <<std :: endl;
   glutPostRedisplay();
   glutTimerFunc(10,myTimer,t);			
  
	}
void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("RGBA and Sound Demo");
  myInit();
  pix[1].readBMPFile("car.bmp",1);
  pix[1].setChromaKey(255,255,255);
 glutDisplayFunc(display);
 glutKeyboardFunc(myKeyboard);
  glutTimerFunc(500,myTimer,1);

  glutMainLoop();
}


