#include <iostream>
#include <glut.h>
#include <fstream>

using namespace std;

void display(void)
{
  
    glClearColor(0.5f,0.98f,0.1f,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,95,0,95);
	//drawing paddle
	glBegin(GL_QUADS);
	glColor3f(0.12,0.3f,0.9f);
	glVertex2f(40,2);
	glVertex2f(54.0,2);
	glVertex2f(54.0,5);
	glVertex2f(40,5);
	
	glEnd();

	//draw Ball
	int ball_x=50; int ball_y=50;
		glColor3f(115.0f/255,4.0f/255,15.0f/255);
	for(float a=0;a<2*3.142;a+=0.01){
		glBegin(GL_POLYGON);
		glVertex2f(ball_x+cos(a)*2.5,(ball_y+0.5)+sin(a)*2.5);
		glVertex2f(ball_x+cos(a+0.01)*2.5,(ball_y+0.5)+sin(a+0.01)*2.5);
		glVertex2f(ball_x,ball_y);
		glEnd();
	}

//drawing bricks
	int x=2.5; int y=70;
	for(int i=0;i<6;i++){

		for(int j=0;j<9;j++){

			glBegin(GL_QUADS);
			float color1 = (25.5*j)/255;
		
	float color2 = (20*j)/255;
	float color3 = (20*j)/255;
	glColor3f(color1,color2,color3);

	glVertex2f(j*10+x,y+(i*4));
	glVertex2f((j*10)+9+x,y+(i*4));
	glVertex2f((j*10)+9+x,y+(i*4)+3.5);
	glVertex2f(j*10+x,y+(i*4)+3.5);
	
	glEnd();
		}
	}
       
	glFlush();
}
 int screenWidth = 1080;
     int screenHeight = 680;

	  int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);

	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(30,30);
	glutCreateWindow("MY First OGL Program");

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}