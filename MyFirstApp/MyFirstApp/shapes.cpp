#include <iostream>
#include <fstream>
#include <string>
#include <glut.h>

using namespace std;

void myDisplay(void)
{
	
	glClearColor(4.3f,12.0f,4.3f,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,20,0,20);

	/*glBegin(GL_POLYGON);

	glVertex2f(2.0,1.0);
	glVertex2f(12.0,1.0);
	glVertex2f(14.0,3.0);
	glVertex2f(1.0,3.0);
	glEnd();

    glBegin(GL_TRIANGLES);
	glVertex2f(1.0,4.0);
	glVertex2f(8.0,17.0);
	glVertex2f(8.0,4.0);
	
	 glBegin(GL_TRIANGLES);
	glVertex2f(9.0,5.0);
	glVertex2f(9.0,15.0);
	glVertex2f(12.0,5.0);
		glEnd();*/

	glBegin(GL_QUADS);

	glVertex2f(1.0,1.0);
	glVertex2f(4.0,1.0);
	glVertex2f(4.0,10.0);
	glVertex2f(1.0,10.0);
	glColor3f(0.1f,0.15f,0.86f);
	glEnd();
	//gates
	glBegin(GL_QUADS);
	glVertex2f(1.0,1.0);
	glVertex2f(2.0,2.0);
	glVertex2f(2.0,5.0);
	glVertex2f(1.0,6.0);
	glColor3f(0.21f,0.41f,0.41f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(3.0,2.0);
	glVertex2f(4.0,1.0);
	glVertex2f(4.0,6.0);
	glVertex2f(3.0,5.0);
	glColor3f(0.21f,0.41f,0.41f);
	glEnd();
	//gates end

	glBegin(GL_TRIANGLES);

	glVertex2f(1.0,10.1);
	glVertex2f(4.0,10.1);
	glVertex2f(2.5,13.0);
	glColor3f(0.34,0.19f,0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2f(4.1,10.1);
	glVertex2f(14.0,10.1);
	glVertex2f(13.0,13.0);
	glVertex2f(2.6,13.0);
	glColor3f(0.69f,0.57f,0.21f);
	glEnd();


	glBegin(GL_QUADS);
	glVertex2f(4.1,1.0);
	glVertex2f(14.0,1.0);
	glVertex2f(14.0,10.0);
	glVertex2f(4.1,10.0);
	glEnd();
	glFlush();

}
    int screenWidth = 640;
     int screenHeight = 480;
    int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);

	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(30,30);
	glutCreateWindow("MY First OGL Program");

	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}