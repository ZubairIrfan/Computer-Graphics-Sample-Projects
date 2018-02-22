#pragma once

#include "includes.h"

class Canvas 
{
  public:
    Canvas(int width, int height, char* windowTitle);// constructor
    void setWindow(float l, float r, float b, float t);
	// changed setViewport float to int
    void setViewport(int l, int r, int b, int t);
    void clearScreen();
    void setBackgroundColor(float r,float g,float b);
    void setColor(float r,float g,float b);
	void setIndexedColor(int);
    	
	
	IntRect getViewport(void); // divulge or make known the viewport data
    RealRect getWindow(void); // divulge or make known the window data
    float getWindowAspectRatio(void);
	
	void drawAxis(GLdouble x1, GLdouble x2, GLdouble y1, GLdouble y2);
	void drawAxis(float r, float g, float b);
	

	float getCP_X(void);
    float getCP_Y(void);

	
	void moveTo(float x,float y);
    void moveTo(Point2 p);
	
	void lineTo(float x,float y);
    void lineTo(Point2 p);
    
    
    // others later
  private:
    Point2 CP; // current position in the world
    IntRect viewport; // the current viewport
    RealRect window; // the current window
}; // end class Cavas

//************************ End of file "canvas.h" ***************************

Canvas::Canvas(int width, int height, char* windowTitle)// constructor
{
  char* argv[1]; // dmmy argument list for glutInit()
  char dummyString[8];
  argv[0] = dummyString; // hook up the pointer
  int argc = 1; // to satisfy glutInit()

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(20, 20);
  glutCreateWindow(windowTitle); // open the screen window
  setWindow(0, (float)width, 0, (float)height); //default world window
  setViewport(0, width, 0, height); //default viewport
  CP.set(0.0f,0.0f); //initialize the CP to (0,0)
}//end Canvas constructor

void Canvas::setWindow(float l, float r, float b, float t)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //gluOrtho2D(l, r, b, t); //set the world window
  glOrtho(l, r, b, t,-10,10); //set the world window
  window.set(l,r,b,t);
}// end setWindow

// Changed float to int in void Canvas
void Canvas::setViewport(int l, int r, int b, int t)
{
  glViewport(l, b, r-l, t-b);
} // end setViewport

IntRect Canvas::getViewport(void) // divulge or make known the viewport data
{
  IntRect rect=IntRect(0,0,0,0);
  rect.set(Canvas::viewport.getl(), Canvas::viewport.getr(), Canvas::viewport.getb(), Canvas::viewport.gett());
  return rect;
}// end getViewport
RealRect Canvas::getWindow(void) // divulge or make known the window data
{
  RealRect window=RealRect();
  window.set(Canvas::window.getl(), Canvas::window.getr(), Canvas::window.getb(), Canvas::window.gett());
  return window;
}// end getwindow
float Canvas::getWindowAspectRatio(void)
{
  return ((window.getr() - window.getl())/(window.gett() - window.getb()));
}// end getWindowAspectRatio

float Canvas::getCP_X(void)
{
	return Canvas::CP.getX();

}

float Canvas::getCP_Y(void)
{

	return Canvas::CP.getY();

}


void Canvas::clearScreen()
{
  glClear(GL_COLOR_BUFFER_BIT);
}// clearScreen

void Canvas::setBackgroundColor(float r,float g,float b)
{
  glClearColor(r, g, b, 0.0);
}// end setBackgroundColor

void Canvas::setColor(float r, float g, float b)
{
  glColor3f(r, g, b);
}//edn setColor

void Canvas::setIndexedColor(int c)
{
	switch(c)
		{
			case 0:	setColor(177.0/255,100.0/255,255.0/255);   break; // violet
			case 1:	setColor(64.0/255,0.0/255,128.0/255);      break; //indigo
			case 2:	setColor(177.0/255,100.0/255,255.0/255);   break; //blue
			case 3:	setColor(0.0/255,255.0/255,0.0/255);   break; // green
			case 4:	setColor(255.0/255,255.0/255,0.0/255);       break; //yellow
			case 5:	setColor(255.0/255,128.0/255,0.0/255);     break; //orange
			case 6:	setColor(255.0/255,0.0/255,0.0/255);   break; //red
			
		}


}


//---------------- draw axis -------------------

//---------------- draw axis -------------------
void Canvas:: drawAxis(GLdouble x1, GLdouble x2, GLdouble y1, GLdouble y2)
{
	
	glEnable(GL_LINE_STIPPLE);
	setColor(0.0f, 0.0f, 1.0f);
	glLineStipple(1, 0x3333);
	glBegin(GL_LINE_STRIP);
		glVertex2f( x1, 0.0 );
		glVertex2f( x2, 0.0 );
	glEnd();
	
	glBegin(GL_LINE_STRIP);
		glVertex2f( 0.0, y1 );
		glVertex2f( 0.0, y2 );
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}
void Canvas::drawAxis(float r, float g, float b)
{

	setColor(r,g,b);

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xFF00);

	moveTo(window.getl(),0.0f);
	lineTo(window.getr(),0.0f);
	moveTo(0.0f,window.gett());
	lineTo(0.0f,window.getb());
	
	glDisable(GL_LINE_STIPPLE);

	
}


void Canvas::moveTo(float x,float y)
{
  CP.set(x,y);
}// end moveTo

void Canvas::moveTo(Point2 p)
{
  CP.set(p.getX(), p.getY());
}// end moveTo


void Canvas::lineTo(float x,float y)
{
	glEnable( GL_BLEND);
  	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  	glHint( GL_LINE_SMOOTH_HINT, GL_NICEST);

	glEnable( GL_LINE_SMOOTH);
	glBegin(GL_LINES);
		glVertex2f(CP.getX(), CP.getY());
		glVertex2f(x, y);
	glEnd();
   glDisable( GL_LINE_SMOOTH);


	//CP.set(x,y);

}// end lineTo
void Canvas::lineTo(Point2 p)

{
   //printf("\n%f	%f",p.getX(),p.getY());

	glEnable( GL_BLEND);
  	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 	glHint( GL_LINE_SMOOTH_HINT, GL_NICEST);

	glEnable( GL_LINE_SMOOTH);
    glBegin(GL_LINES);
		glVertex2f(CP.getX(), CP.getY());
		glVertex2f(p.getX(),p.getY());
   glEnd();
   glDisable( GL_LINE_SMOOTH);



}// end lineTo


