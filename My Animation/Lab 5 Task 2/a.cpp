#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>

#include "RGBA.h"

RGBApixmap pix[10];
double xx = 0, yy=0;
int pos_x=0,pos_y=0;
int action =0;
bool check=false;
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
	glClearColor(1.0f,1.0f,1.0f,0.0f); 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,1000,0,1000);
	glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D,2001);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(xx,yy);
	 glVertex2d(pos_x+0,pos_y+0);
	 glTexCoord2f(xx+0.2,yy);
	 glVertex2d(pos_x+300,pos_y+0);
	 glTexCoord2f(xx+0.2,yy+0.25);
	 glVertex2d(pos_x+300,pos_y+300);
	  glTexCoord2f(xx,yy+0.25);
	 glVertex2d(pos_x+0,pos_y+300);
	 glEnd();

	 //example

	 glDisable(GL_TEXTURE_2D);
	 
	  glFlush();
}
void myTimer(int t){
	//walk
	if(action==1){
	if(xx+0.2>=1){
		xx=0;
	}
	else
		xx=xx+0.2;
	if(check==false){
		pos_x=pos_x+30;
	}else
		pos_x=pos_x-30;

	if(pos_x+30>850)
		check=true;
	if(pos_x<0)
		check=false;
	}
	//sit
	if(action==2){
	if(xx+0.2>=1){
		xx=0;
		pos_y=pos_y+75;
	}
	else
		xx=xx+0.2;
		pos_y=pos_y-15;
	}

	//jump
	if(action==3){
	if(xx+0.2>=1){
		xx=0;
		pos_y = pos_y-40;
	}
	else
		xx=xx+0.2;
	if(xx<0.5){
		pos_y=pos_y+40;
	}
	else
		pos_y=pos_y-40;
	}
	//dance
	if(action==4){
	if(xx+0.2>=1){
		xx=0;
	}
	else
		xx=xx+0.2;
	
	}
	
	
	std :: cout <<y1 <<std :: endl;
	glutPostRedisplay();
   glutTimerFunc(200,myTimer,t);


}
void myKeyboard(unsigned char key, int x, int y){
	if(key=='a'){
		xx=0;
		yy=0.75;
		action=1;
	}
	if(key=='s'){
		xx=0;
		yy=0.5;
		action=2;
	}
	if(key=='w'){
		xx=0;
		yy=0.25;
		action=3;
	}
	if(key=='d'){
		xx=0;
		yy=0;
		action=4;
	}
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
  pix[0].readBMPFile("stick.bmp",1);
  pix[0].setChromaKey(255,255,255);
  pix[0].setTexture(2001);
  
    glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
  glutTimerFunc(200,myTimer,1);
  glutMainLoop();
}