#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>
#include "RGBA.h"


RGBApixmap pix[6];
bool check=true;
int camera_x=0, camera_y=0;
void myInit(void)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  
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
  gluOrtho2D(0,640,0,480);
	 glViewport(camera_x,camera_y, 400,400);
     glRasterPos2f(0,0);
	 pix[0].mDraw();
	 glViewport(0,0,200,200);
	 glRasterPos2f(150,0);
	 pix[1].mDraw();
	 glFlush();
  
}

void myTimer(int t)
{
	if(check==true)
	camera_x=camera_x-2;
	else
		camera_x=camera_x+2;

	if(camera_x<=-500){
		check=false;
	}
	if(camera_x>=0){
		check=true;
	}
		std :: cout << camera_x <<std :: endl;
   glutPostRedisplay();
   glutTimerFunc(100,myTimer,t);			
  
	}
void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("RGBA and Sound Demo");
  myInit();
  pix[0].readBMPFile("a.bmp",1);
  pix[1].readBMPFile("car.bmp",1);
  pix[1].setChromaKey(255,255,255);
 glutDisplayFunc(display);
    
  glutTimerFunc(500,myTimer,1);

  glutMainLoop();
}


