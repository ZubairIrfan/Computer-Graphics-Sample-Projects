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

std::vector<Point2> myVerticeList;

int prev_x = 0,prev_y=0;
int curr_x = 0,curr_y=0;
bool first_point=true;
int count =0;
RGBApixmap pix;

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
void drawPolygon(){
	
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,640,0,480);
	 glBegin(GL_POLYGON);

		 for(int i=0; i<myVerticeList.size(); i++){

			 glVertex2f(myVerticeList.at(i).x,480-myVerticeList.at(i).y);
	 }
		 glEnd();
}
void display(void)
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f); 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,640,0,480);
	 glRasterPos2f(0,0);
	 pix.mDraw();
	 count =0;
	 std :: cout << count <<std :: endl;
	 if(curr_x==prev_x && curr_y==prev_y && curr_x>0){
		 drawPolygon();
	 }
	 else if(curr_x==prev_x && curr_y==prev_y){

	 }
	 else
	 {
		 myVerticeList.push_back(Point2(prev_x,prev_y));
		 myVerticeList.push_back(Point2(curr_x,curr_y));
	glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,640,0,480);
	  glColor3f(0.4f,0.6f,0.1f);
	  for(int i=0; i < myVerticeList.size(); i=i+2){
		   glBegin(GL_LINES);
		   glVertex2d(myVerticeList.at(i).x,480-myVerticeList.at(i).y);
		   glVertex2d(myVerticeList.at(i+1).x,480-myVerticeList.at(i+1).y);
	 glVertex2d(curr_x,curr_y);
	 glEnd();
	  }
	
	 }
	 glFlush();
}
void myMouse(int key,int state,int x,int y){
	count++;
	std :: cout << "count is " <<std :: endl;
	std :: cout << count <<std :: endl;
	if(key==GLUT_LEFT_BUTTON){
		std :: cout << x <<std :: endl;
	std :: cout << y <<std :: endl;
	if(first_point==true && count ==2){
		 curr_x=x;
		 curr_y=y;
		 first_point=false;
	 }
	else if(count==2 || count ==4)
	{
		std :: cout << "count equals 2" <<std :: endl;
       prev_x = curr_x;
	   prev_y= curr_y;
	   curr_x = x;
	   curr_y=y;
	   glutPostRedisplay();
	}
	}
}

void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Lab 4");
   pix.readBMPFile("p4.bmp",1);
  myInit();
  glutDisplayFunc(display);
  glutMouseFunc(myMouse);
  glutMainLoop();
}
