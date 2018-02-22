#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>
#include "RGBA.h"

int x=0, y=0;
RGBApixmap pix[10];
void myInit(void)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
   
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
  //or glAlphaFunc(GL_NOTEQUAL,0.0);// accept fragment if fragment alpha not= reference alpha i.e. 1.0

 
  glViewport(0, 0, 640, 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 
}
void display(void)
{
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,1000,0,1000);
	 for(int i=0; i<5;i++){
		 for(int j=0; j<5;j++){
	 glViewport(x,y,400,400);
	  glRasterPos2d(0,0);
  pix[0].mDraw();
  x=x+120;
	 }
		 x=0;
		 y=y+120;
	 }
	  glFlush();
}
void myTimer(int t){

}
void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("JUNGLE");
  myInit();
  pix[0].readBMPFile("bg.bmp",1);

      glutDisplayFunc(display);
 // glutTimerFunc(200,myTimer,1);
  glutMainLoop();
}