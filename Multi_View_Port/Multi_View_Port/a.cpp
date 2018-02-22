
#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <glut.h>

using std::cout;
using std::fstream;
using std::ios;

const int screenWidth = 640;	   // width of screen window in pixels
const int screenHeight = 480;	   // height of screen window in pixels

void drawPolyLineFile(char * fileName)
{
	fstream inStream;

	inStream.open(fileName, ios ::in);	// open the file

	if(inStream.fail())
		{ cout << "can't open it!";return;}

	//glClear(GL_COLOR_BUFFER_BIT);      // clear the screen

	//GLint numpolys, numPoints, x ,y;

	GLfloat numpolys, numPoints, x ,y;
	inStream >> numpolys;		           // read the number of polylines

	for(int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x+1800, y+1800);
		}
		glEnd();
	}

	inStream.close();
}

 void myInit(void)
 {
    	glClearColor(0.3f,0.56f,1.0f,1.0f); // background color is white
    	glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
 	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(-(GLdouble)screenWidth, (GLdouble)screenWidth, -(GLdouble)screenHeight, (GLdouble)screenHeight);//dino window
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);//dino window

	glViewport(0,0,screenWidth,screenHeight);

}

 const int numMotifs =1;
 float H = 400;
void myDisplay(void)
{
     glClear(GL_COLOR_BUFFER_BIT);      // clear the screen
     glColor3f(1.0f, 0.0f, 0.0f);         // drawing color is black

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
 //glViewport(0,240,400,400);
 //    drawPolyLineFile("birdhead.dat");	
	// glViewport(0,0,840,480);// send all output to display
 //    drawPolyLineFile("house.dat");
	 glViewport(20,20,640,480);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(-1600,640*12,-1600,480*12);
	 float x=90;
	 glPushMatrix();
	 for(float i=0; i<2*3.142; i = i+((2*3.142)/12)){
		 
		  glTranslatef(800*cos(i), 800*sin(i),0);
		  glPushMatrix();
		   glRotatef(x,0,0,1);
		   drawPolyLineFile("dino.dat");
		   glPopMatrix();
		  x+=30;
		
	 }
    glPopMatrix();
     glutSwapBuffers();
}

int main(int argc, char** argv)
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(10, 10); // set window position on screen
	glutCreateWindow("Dino Line Drawing"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
	return 1;
}

