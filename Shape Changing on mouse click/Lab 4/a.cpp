#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>
#include <vector>
#include "RGBA.h"

class Point2{
public: float x,y;
 		Point2(float xx,float yy){
			x=xx;
			y=yy;
		}
		Point2(){
			x=y=0;
		}
		void set(float dx, float dy){
		x=dx;
		y=dy;
		}
};
RGBApixmap pix;
std::vector<Point2> myVerticeList;
int R=50;
float p_start=0;
float n=3;
void computeVertices(int n,float start){
	myVerticeList.clear();
	Point2  *pointlist = new Point2[n];
	float angle_inc = (2*(3.142))/n; 
	float current_angle = start;
	for(int i=0; i<n;i++){
		float x= R *  cos(current_angle);
		float y= R * sin(current_angle);
		myVerticeList.push_back(Point2(x,y));
		current_angle = current_angle + angle_inc;
	}
}

void drawPolygon(int x, int y){
	glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,100,0,100);
	 glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D,2001);
	 int m=0;int n=0;
	glBegin(GL_POLYGON);
	for(int i=0; i< myVerticeList.size();i++){
		//glTexCoord2f(0.5+(myVerticeList.at(i).x)/2,0.5+(myVerticeList.at(i).y)/2);
		glVertex2f(x + myVerticeList.at(i).x, y + myVerticeList.at(i).y);
		
	}
	
	
	glEnd();
}
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
	 gluOrtho2D(0,100,0,100);
	 
	 computeVertices(n,p_start);
	 drawPolygon(50,50);
	  

	// glColor3f(0.4,0.8,0.2);
	//glBegin(GL_POLYGON);
	// glVertex2f(20+R*cos(0.0),20+R*sin(0.0));
	// glVertex2f(20+R*cos((2*2*3.142)/5),20+R*sin((2*2*3.142)/5));
	//  glVertex2f(20+R*cos((4*2*3.142)/5),20+R*sin((4*2*3.142)/5));
	// /glVertex2f(20+R*cos((1*2*3.142)/5),20+R*sin((1*2*3.142)/5));
	// // glVertex2f(20+R*cos((3*2*3.142)/5),20+R*sin((3*2*3.142)/5));
	 
	 glFlush();
}

void myTimer(int t)
{
	p_start = p_start+ 0.04;
   glutPostRedisplay();
   glutTimerFunc(100,myTimer,t);			
  
	}
void myMouse(int key,int state,int x,int y){
	
	
	if(key==GLUT_LEFT_BUTTON){
		n=n+0.5;
	}
	if(key==GLUT_RIGHT_BUTTON){
		if(n>3){
			n=n-0.5;
		}
	}
	glutPostRedisplay();
}

void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Lab 4");
  myInit();
  pix.readBMPFile("cake.bmp",1);
  pix.setTexture(2001);
  glutDisplayFunc(display);
  glutMouseFunc(myMouse);
  glutTimerFunc(500,myTimer,1);
  glutMainLoop();
}
