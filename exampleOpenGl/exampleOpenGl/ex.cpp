#include <iostream>
#include <fstream>
#include <string>
#include <glut.h>

using namespace std;

void display(void){

	
	
	glClearColor(0.9f,0.001f,0.54f,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glFlush();

}
int width = 640 , height = 480;

int main(int c,char **v){
	
	glutInit(&c,v);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width,height);
	glutInitWindowPosition(30,30);
	glutCreateWindow("OGL Program");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}