#include <iostream>
#include <fstream>
#include <string>
#include <glut.h>

using namespace std;
float left1,top1 = 0;
void display(void){
	glClearColor(0.9f,0.001f,0.54f,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glViewport(left1,top1,640,480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,20,0,20);
	
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(20,0);
	glVertex2f(10,30);
	glEnd();
	glFlush();

}
int width = 640 , height = 480;

void reshapeHandler(int w,int h){
left1 = (w-640)/2;
top1 = (h-480)/2;
glutPostRedisplay();
}

int main(int c,char **v){
	
	glutInit(&c,v);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width,height);
	glutInitWindowPosition(30,30);
	glutCreateWindow("OGL Program");
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeHandler);

	glutMainLoop();

	return 0;
}