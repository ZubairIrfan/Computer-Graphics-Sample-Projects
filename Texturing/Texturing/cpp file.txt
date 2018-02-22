#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>

#include "RGBA.h"

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
	glClearColor(0.0f,0.0f,0.0f,0.0f); 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,1000,0,1000);
	
	 glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D,2001);
	  glColor3f(0.64f,0.2f,0.0f);
	 glBegin(GL_POLYGON);
	// glTexCoord2f(0,0);
	 glVertex2f(50,150);
	// glTexCoord2f(1,0);
	 glVertex2f(650,0);
	// glTexCoord2f(1,1);
	 glVertex2f(660,30);
	 //glTexCoord2f(0,1);
	 glVertex2f(60,185);
	 glEnd();

	 //wall
	  glBindTexture(GL_TEXTURE_2D,2001);
	  glColor3f(0.4f,0.1f,0.6f);
	  glBegin(GL_POLYGON);
	glTexCoord2f(0,0);
	 glVertex2f(65,180);
	 glTexCoord2f(1,0);
	 glVertex2f(660,30);
	 glTexCoord2f(1,1);
	 glVertex2f(670,540);
	 glTexCoord2f(0,1);
	 glVertex2f(65,540);
	 glEnd();

	 //roof
	  glBindTexture(GL_TEXTURE_2D,2002);
	  glColor3f(0.9f,0.1f,0.6f);
	  glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2f(0,540);
	 glTexCoord2f(1,0);
	 glVertex2f(680,540);
	 glTexCoord2f(1,1);
	 glVertex2f(820,980);
	 glTexCoord2f(0,1);
	 glVertex2f(210,890);
	 glEnd();
	
	  glColor3f(0.3f,0.1f,0.93f);
	  glBegin(GL_POLYGON);
	// glTexCoord2f(0,0);
	 glVertex2f(790,900);
	// glTexCoord2f(1,0);
	 glVertex2f(880,570);
	// glTexCoord2f(1,1);
	 glVertex2f(920,575);
	 //glTexCoord2f(0,1);
	 glVertex2f(820,980);
	 glEnd();

	  glBindTexture(GL_TEXTURE_2D,2001);
	  glColor3f(0.3f,0.8f,0.93f);
	  glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2f(660,30);
	 glTexCoord2f(1,0);
	 glVertex2f(880,185);
	 glTexCoord2f(1,1);
	 glVertex2f(880,570);
	 glTexCoord2f(0,1);
	 glVertex2f(790,900);
	  glVertex2f(675,550);
	  	  glVertex2f(660,550);
	 glEnd();

	  glColor3f(0.64f,0.2f,0.0f);
	  glBegin(GL_POLYGON);
	// glTexCoord2f(0,0);
	 glVertex2f(650,0);
	// glTexCoord2f(1,0);
	 glVertex2f(885,170);
	// glTexCoord2f(1,1);
	 glVertex2f(885,200);
	 //glTexCoord2f(0,1);
	 glVertex2f(660,40);
	 glEnd();

	 //door
	 glBindTexture(GL_TEXTURE_2D,2003);
	  glColor3f(0.66f,0.19f,0.83f);
	  glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2f(400,90);
	glTexCoord2f(1,0);
	 glVertex2f(550,60);
	 glTexCoord2f(1,1);
	 glVertex2f(550,410);
	 glTexCoord2f(0,1);
	 glVertex2f(400,415);
	 glEnd();
	 //window
	  glBindTexture(GL_TEXTURE_2D,2004);
	  glColor3f(0.66f,0.19f,0.83f);
	  glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2f(720,320);
	glTexCoord2f(1,0);
	 glVertex2f(830,340);
	 glTexCoord2f(1,1);
	 glVertex2f(830,600);
	 glTexCoord2f(0,1);
	 glVertex2f(720,620);
	 glEnd();
	 //window
	  glBindTexture(GL_TEXTURE_2D,2004);
	  glColor3f(0.66f,0.19f,0.83f);
	  glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2f(150,260);
	glTexCoord2f(1,0);
	 glVertex2f(250,250);
	 glTexCoord2f(1,1);
	 glVertex2f(250,420);
	 glTexCoord2f(0,1);
	 glVertex2f(150,430);
	 glEnd();


	 glFlush();
}

void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Texturing");
  myInit();
  pix[0].readBMPFile("wall.bmp",1);
  pix[0].setTexture(2001);
  pix[1].readBMPFile("roof.bmp",1);
  pix[1].setTexture(2002);
  pix[2].readBMPFile("door.bmp",1);
  pix[2].setTexture(2003);
  pix[3].readBMPFile("window.bmp",1);
  pix[3].setTexture(2004);

  glutDisplayFunc(display);
  
  glutMainLoop();
}