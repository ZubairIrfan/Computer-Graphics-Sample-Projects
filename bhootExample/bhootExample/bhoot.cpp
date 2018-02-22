#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
float gx,gy,r=4,gd=1;
void drawBhoot(int x, int y){
	//head
	glColor3f(145.0f/255,34.0f/255,65.0f/255);
	for(float a=0;a<3.142;a+=0.01){
		glBegin(GL_POLYGON);
		glVertex2f(x+cos(a)*r,y+sin(a)*r);
		glVertex2f(x+cos(a+0.01)*r,y+sin(a+0.01)*r);
		glVertex2f(x,y);
		glEnd();
	}
	//body
	glBegin(GL_POLYGON);
	glVertex2f(x+r,y);
	glVertex2f(x+r,y-r);
	glVertex2f(x+r/2,y-r+gd);
	glVertex2f(x,y-r);
	glVertex2f(x-r/2,y-r+gd);
	glVertex2f(x-r,y-r);
	glVertex2f(x-r,y);
	glEnd();

	//Eyes
	glColor3f(115.0f/255,4.0f/255,15.0f/255);
	for(float a=0;a<2*3.142;a+=0.01){
		glBegin(GL_POLYGON);
		glVertex2f((x-1)+cos(a)*0.5,(y+0.5)+sin(a)*0.5);
		glVertex2f((x-1)+cos(a+0.01)*0.5,(y+0.5)+sin(a+0.01)*0.5);
		glVertex2f(x-1,y+0.5);
		glEnd();
	}
	glColor3f(115.0f/255,4.0f/255,15.0f/255);
	for(float a=0;a<2*3.142;a+=0.01){
		glBegin(GL_POLYGON);
		glVertex2f((x+1)+cos(a)*0.5,(y+0.5)+sin(a)*0.5);
		glVertex2f((x+1)+cos(a+0.01)*0.5,(y+0.5)+sin(a+0.01)*0.5);
		glVertex2f((x+1),(y+0.5));
		glEnd();
	}

}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,0,100);
    drawBhoot(50,10);
  glFlush();
  
}
void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
 glutCreateWindow("Bhoot");
    
  glutDisplayFunc(display);
  glutMainLoop();
}